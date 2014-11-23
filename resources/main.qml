/********************************************************
** 
** Copyright (C) 2014 godbod and/or its subsidiary (-ies)
** Contact : gkounkou@gmail.com
**
*********************************************************/

import QtQuick 1.1

Rectangle
{
    id    : chatScreen

    height: 630
    width : 300

    property bool   varVisibleSPSTitle  : true
    property bool   varVisibleSPS       : true
    property string nameP               : ""
    property bool   textTypeSearch      : true
    property bool   focusSearch         : false
    property string textInputSearch     : "tap your message..."

    property string blue                : "#2672EC"
    property string green               : "#267234"
    property string red                 : "#660000"
    property string iblue               : "#007aff"
    

    property int    cacheBuff           : 65536

    signal sendMessage(string messageAEnvoyer)
  
    Image
    {
        id      : wallpaper
        height  : parent.height
        width   : parent.width
        fillMode: Image.PreserveAspectCrop
        source  : "wallpaper.jpg"
        smooth  : true
    }

    Rectangle
    {
        id:searchBar

        anchors
        {
            bottom      : parent.bottom
            bottomMargin: 8
            left        : parent.left
            leftMargin  : 20
            right       : parent.right
            rightMargin : 20
        }

        height      : 35
        width       : parent.width
        radius      : 1
        color       : "white"
        border.color: "white"
        border.width: 1
        smooth      : true

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                textInputSearch = ''
                focusSearch     = true
            }
        }

        TextInput
        {
            id: textInput

            anchors
            {
                left          : parent.left
                leftMargin    : 8
                right         : searchBar.right
                rightMargin   : 8
                verticalCenter: parent.verticalCenter
            }

            focus         : focusSearch
            font.family   : "Ubuntu Mono"
            font.pointSize: 10
            color         : "#0F0F0F"
            text          : textInputSearch
            smooth        : true

            onAccepted:
            {
                sendMessage(textInput.text)
                textInput.text  = ''
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    textInputSearch= ""
                    focusSearch    = true
                    textTypeSearch = false
                }
                acceptedButtons: Qt.LeftButton | Qt.RightButton
            }
        }
    }

    Component
    {
        id: listDelegateSPS

        Rectangle
        {
            id:delegateItem

            //width     : (name.length*8)>(listViewSPS.width)?listViewSPS.width:(name.length*8)
            width       : listViewSPS.width 
            height      : nom.height + 14 
            clip        : true
            smooth      : true
            color       : green 
            border.color: "transparent"
            border.width: 1
            radius      : 10

            Text
            {
                id:nom

                anchors
                {
                   left          : delegateItem.left
                   leftMargin    : 10
                   verticalCenter: delegateItem.verticalCenter
                   right         : delegateItem.right
                   rightMargin   : 5
                   topMargin     : 0
                   bottomMargin  : 0
                }

                text          : name 
                font.family   : "Ubuntu Mono"
                font.pointSize: 10
                color         : "white"
                smooth        : true
                width         : parent.width
                wrapMode      : Text.WordWrap
                clip          : true
                textFormat    : Text.RichText
            }

            ListView.onAdd: ParallelAnimation
            {
                 PropertyAction
                 {
                     target  : delegateItem;
                     property: "height";
                     value   : 0
                 }
                 NumberAnimation
                 {
                     target     : delegateItem;
                     property   : "height";
                     to         : nom.height + 14 
                     duration   : 300;
                     easing.type: Easing.InOutBack
                 }
                 ColorAnimation
                 {
                     target   : delegateItem
                     property : "color"
                     to       : green 
                     duration : 300
                 }
                 NumberAnimation
                 {
                     target     : delegateItem;
                     property   : "scale";
                     from       : 0
                     to         : 1
                     duration   : 300
                     easing.type: Easing.InOutBack
                 }
            }

            ListView.onRemove: ParallelAnimation
            {
                PropertyAction
                {
                    target  : delegateItem;
                    property: "ListView.delayRemove";
                    value   : true
                }
                ParallelAnimation
                {
                    NumberAnimation
                    {
                        target     : delegateItem;
                        property   : "height";
                        to         : 0
                        duration   : 300;
                        easing.type: Easing.InOutQuart
                    }
                    NumberAnimation
                    {
                        target     : delegateItem;
                        property   : "scale";
                        to         : 0
                        duration   : 300;
                        easing.type: Easing.InOutQuart
                    }
                    NumberAnimation
                    {
                        property    : "width";
                        duration    : 300
                        easing.type : Easing.InOutQuart
                    }
                }
            }
            Behavior on height
            {
                NumberAnimation
                {
                    property   : "height";
                    duration   : 300;
                    easing.type: Easing.InOutQuad
                }
            }
            Behavior on color
            {
                ColorAnimation
                {
                    duration: 200
                }
            }
        }
    }

    ListView
    {
        id         : listViewSPS
        width      : parent.width
        height     : parent.height - parent.height/5
        clip       : true
        opacity    : 1
        cacheBuffer: cacheBuff
        visible    : varVisibleSPS
        spacing    : 3 
        focus      : true

        Behavior on width
        {
            NumberAnimation
            {
                property   : "width"
                duration   : 300 
                easing.type: Easing.InOutQuart
            }
        }

        anchors
        {
            left        : parent.left
            leftMargin  : 20
            top         : parent.top
            topMargin   : 50 
            right       : parent.right
            rightMargin : 20
        }

        onContentHeightChanged: 
        { 
           listViewSPS.positionViewAtEnd();
        }

        model   : myModelsps
        delegate: listDelegateSPS
    }
    /*
    ScrollBar
    {
       flickable : listViewSPS;
    }
    */
}
