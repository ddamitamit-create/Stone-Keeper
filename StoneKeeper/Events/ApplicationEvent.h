#pragma once

#include <format>
#include "Event.h"

namespace StoneKeeper {

    class ENGINE_API WindowResizedEvent : public Event {
    public:
        WindowResizedEvent(unsigned int width,unsigned int height)
            : m_Width(width), m_Height(height) {}

        [[nodiscard]] inline unsigned int GetWidth() const { return m_Width; }
        [[nodiscard]] inline unsigned int GetHeight() const { return m_Height; }

        [[nodiscard]] std::string ToString() const override {
                return std::format("WindowResizedEvent: Width:{}, height:{}", m_Width, m_Height);
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

        private:
            unsigned int m_Width, m_Height;
    };

    class ENGINE_API WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ENGINE_API AppTickEvent : public Event {
    public:
        AppTickEvent() = default;

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ENGINE_API AppUpdateEvent : public Event {
    public:
        AppUpdateEvent() = default;

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ENGINE_API AppRenderEvent : public Event {
    public:
        AppRenderEvent() = default;

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}