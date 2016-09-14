/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2016 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_WIDGET_LOADER_HPP
#define TGUI_WIDGET_LOADER_HPP


#include <TGUI/Loading/DataIO.hpp>
#include <TGUI/Container.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Class to load widgets from a text file
    ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API WidgetLoader
    {
    public:
        using LoadFunction = std::function<Widget::Ptr(std::shared_ptr<DataIO::Node>, Widget::Ptr)>;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads a container and its child widgets from a stream containing a widget file
        ///
        /// @param parent  The parent container for the child widget
        /// @param stream  Stream containing the widget file
        ///
        /// @note You should use the loadWidgetsFromFile or loadWidgetsFromSteam functions in Gui and Container
        ///       instead of calling this function directly.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static void load(Container::Ptr parent, std::stringstream& stream);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the load function for a certain widget type
        ///
        /// @param type         Type of the widget
        /// @param loadFunction New load function
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static void setLoadFunction(const std::string& type, const LoadFunction& loadFunction);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves the load function of a certain widget type
        ///
        /// @param type  Type of the widget
        ///
        /// @return Function called to load the widget
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static const LoadFunction& getLoadFunction(const std::string& type);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:
        static std::map<std::string, LoadFunction> m_loadFunctions;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_WIDGET_LOADER_HPP
