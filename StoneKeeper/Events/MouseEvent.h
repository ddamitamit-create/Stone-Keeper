#pragma once

#include <format>
#include "Event.h"

namespace StoneKeeper {
    class ENGINE_API MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y) {}

        [[nodiscard]] inline float GetX() const { return m_MouseX; }
        [[nodiscard]] inline float GetY() const { return m_MouseY; }

        [[nodiscard]] std::string ToString() const override {
            return std::format("MouseMovedEvent: ({}, {})", m_MouseX, m_MouseY);
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_MouseX, m_MouseY;
    };

    class ENGINE_API MouseScrolledEvent : public Event {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset) {}

        [[nodiscard]] inline float GetXOffset() const { return m_XOffset; }
        [[nodiscard]] inline float GetYOffset() const { return m_YOffset; }

        [[nodiscard]] std::string ToString() const override {
            return std::format("MouseScrolledEvent: ({}, {})", m_YOffset, m_YOffset);
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_XOffset, m_YOffset;
    };

    class ENGINE_API MouseButtonEvent : public Event {
        public:
            [[nodiscard]] inline int GetMouseButton() const { return m_Button; }

            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        protected:
            MouseButtonEvent(int button)
                : m_Button(button) {}

            int m_Button;
    };

    class ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {}

            [[nodiscard]] std::string ToString() const override {
                return std::format("MouseButtonPressedEvent: {}", m_Button);
            }

        EVENT_CLASS_TYPE(MouseButtonPressed);
    };


    class ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent {
        public:
            MouseButtonReleasedEvent(int button)
                : MouseButtonEvent(button) {}
            [[nodiscard]] std::string ToString() const override {
                return std::format("MouseButtonReleasedEvent: {}", m_Button);
            }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };


}