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

    height: 600
    width : 300


    property bool   varVisibleSPSTitle  : true
    property bool   varVisibleSPS       : true
    property string nameP               : ""
    property bool   textTypeSearch      : true
    property bool   focusSearch         : false
    property string textInputSearch     : "tap your message..."
    property int    index               : 1


    property alias  count               : listViewSPS.count

    
    property string blue                : "#2672EC"
    property string green               : "#267234"
    property string red                 : "#660000"
    

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
            bottomMargin: 10
            left        : parent.left
            leftMargin  : 20
            right       : parent.right
            rightMargin : 20
        }

        height      : 40
        width       : parent.width
        radius      : 2
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
            font.family   : "Helvetica"
            font.pointSize: 11
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

            width       : (name.length*8)>(listViewSPS.width)?listViewSPS.width:(name.length*8)
            //height      : nom.height * 1.5 + 20
            height      : nom.height + 14 
            clip        : true
            smooth      : true
            color       : green 
            border.color: "black"
            border.width: 0
            radius      : 5

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
                font.family   : "Helvetica"
                font.pointSize: 11
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
                     duration   : 500;
                     easing.type: Easing.InOutBack
                 }
                 ColorAnimation
                 {
                     target   : delegateItem
                     property : "color"
                     to       : green
                     duration : 500
                 }
                 NumberAnimation
                 {
                     target     : delegateItem;
                     property   : "scale";
                     from       : 0
                     to         : 1
                     duration   : 500
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
                        duration   : 700;
                        easing.type: Easing.InOutQuart
                    }
                    NumberAnimation
                    {
                        target     : delegateItem;
                        property   : "scale";
                        to         : 0
                        duration   : 700;
                        easing.type: Easing.InOutQuart
                    }
                    NumberAnimation
                    {
                        property    : "width";
                        duration    : 700
                         easing.type: Easing.InOutQuart
                    }
                }
            }
            Behavior on height
            {
                NumberAnimation
                {
                    property   : "height";
                    duration   : 500;
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
        spacing    : 5 
        focus      : true

        Behavior on width
        {
            NumberAnimation
            {
                property   : "width"
                duration   : 500 
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
}
