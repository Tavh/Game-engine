#pragma once

#include "skypch.h"

#include "engine/Core.h"
#include "engine/events/Event.h"

const std::string DEFAULT_WINDOW_TITLE = "Sky engine";
const int DEFAULT_WINDOW_WIDTH = 2560;
const int DEFAULT_WINDOW_HEIGHT = 1440;

namespace Sky {
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = DEFAULT_WINDOW_TITLE,
					unsigned int width = DEFAULT_WINDOW_WIDTH,
					unsigned int height = DEFAULT_WINDOW_HEIGHT) : Title(title), Width(width), Height(height) {}
	};

	// Interface representing a desktop system based on Window
	class SKY_API Window
	{
		public:
			using EventCallbackFn = std::function<void(Event&)>;
			
			virtual ~Window() {}

			virtual void OnUpdate() = 0;

			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			// Window attributes
			virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
			virtual void SetVSync(bool enabled) = 0;
			virtual bool IsVSync() const = 0;

			static Window* Create(const WindowProps& props = WindowProps());
	};
}