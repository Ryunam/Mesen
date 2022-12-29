#pragma once
#include "stdafx.h"
#include "FrameInfo.h"
#include "EmulationSettings.h"
#include "Console.h"
#include "../Utilities/nes_ntsc.h"
#include "../Libretro/libretro.h"

#define FPS_MESEN_NTSC		60.098811862348404716732985230828
#define FPS_MESEN_PAL		50.006977968268290848936010226333
#define FPS_FCEUMM_NTSC		(1008307711.0 / 16777215.0)
#define FPS_FCEUMM_PAL		(838977920.0 / 16777215.0)
#define FPS_INTEGER_NTSC	60.0
#define FPS_INTEGER_PAL		50.0

enum fps_mode {
	FPS_MESEN,
	FPS_FCEUMM,
	FPS_INTEGER
};
static fps_mode set_fps_mode = FPS_MESEN;

class VideoRenderer
{
private:
	std::shared_ptr<Console> _console;
	retro_video_refresh_t _sendFrame = nullptr;
	retro_environment_t _retroEnv = nullptr;
	bool _skipMode = false;
	int32_t _previousHeight = -1;
	int32_t _previousWidth = -1;
public:
	VideoRenderer(std::shared_ptr<Console> console, retro_environment_t retroEnv)
	{
		_console = console;
		_retroEnv = retroEnv;
	}

	~VideoRenderer() { }

	void UpdateFrame(void *frameBuffer, uint32_t width, uint32_t height);

	void GetSystemAudioVideoInfo(retro_system_av_info &info, int32_t maxWidth = 0, int32_t maxHeight = 240)
	{
		_console->GetSettings()->ClearFlags(EmulationFlags::IntegerFpsMode);
		if (set_fps_mode == FPS_INTEGER)
			_console->GetSettings()->SetFlags(EmulationFlags::IntegerFpsMode);

		if (set_fps_mode == FPS_MESEN)
			info.timing.fps = _console->GetModel() == NesModel::NTSC ? FPS_MESEN_NTSC : FPS_MESEN_PAL;
		else if (set_fps_mode == FPS_FCEUMM)
			info.timing.fps = _console->GetModel() == NesModel::NTSC ? FPS_FCEUMM_NTSC : FPS_FCEUMM_PAL;
		else if (set_fps_mode == FPS_INTEGER)
			info.timing.fps = _console->GetModel() == NesModel::NTSC ? FPS_INTEGER_NTSC : FPS_INTEGER_PAL;

		info.timing.sample_rate = _console->GetSettings()->GetSampleRate();

		float ratio = (float)_console->GetSettings()->GetAspectRatio(_console);
		if(ratio == 0.0f)
			ratio = (float)256 / 240;

		bool staticar = (bool)_console->GetSettings()->GetStaticAspectRatio();
		if(!staticar)
			ratio *= (float)_console->GetSettings()->GetOverscanDimensions().GetScreenWidth() / _console->GetSettings()->GetOverscanDimensions().GetScreenHeight() / 256 * 240;

		if(_console->GetSettings()->GetScreenRotation() % 180)
			info.geometry.aspect_ratio = ratio == 0.0f ? 0.0f : 1.0f / ratio;
		else
			info.geometry.aspect_ratio = ratio;

		info.geometry.base_width = _console->GetSettings()->GetOverscanDimensions().GetScreenWidth();
		info.geometry.base_height = _console->GetSettings()->GetOverscanDimensions().GetScreenHeight();

		info.geometry.max_width = maxWidth;
		info.geometry.max_height = maxHeight;

		if(maxHeight > 0 && maxWidth > 0) {
			_previousWidth = maxWidth;
			_previousHeight = maxHeight;
		}
	}

	void SetVideoCallback(retro_video_refresh_t sendFrame);
	void SetSkipMode(bool skip);
};
