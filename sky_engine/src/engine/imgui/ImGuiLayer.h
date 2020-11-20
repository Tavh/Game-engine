#pragma once

#include "engine/Core.h"
#include "engine/Layer.h"

#include "engine/Events/ApplicationEvent.h"
#include "engine/Events/KeyEvent.h"
#include "engine/Events/MouseEvent.h"

namespace Sky {

	class SKY_API ImGuiLayer : public Layer
	{
		public:
			ImGuiLayer();
			~ImGuiLayer();

			void OnAttach();
			void OnDetach();
			void OnUpdate();
			void OnEvent(Event& event);
		private:
			bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
			bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
			bool OnMouseMovedEvent(MouseMovedEvent& event);
			bool OnMouseScrolledEvent(MouseScrolledEvent& event);
			bool OnKeyPressedEvent(KeyPressedEvent& event);
			bool OnKeyTypedEvent(KeyTypedEvent& event);
			bool OnKeyReleasedEvent(KeyReleasedEvent& event);
			bool OnWindowResizeEvent(WindowResizeEvent& event);

			float m_Time = 0.0f;
	};

}