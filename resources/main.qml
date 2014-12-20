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
    width : 500

    property bool   varVisibleSPSTitle  : true
    property bool   varVisibleSPS       : true
    property string nameP               : ""
    property int    idP                 : 0
    property bool   textTypeSearch      : true
    property bool   focusSearch         : false
    property string textInputSearch     : "tap your message..."

    property string blue                : "#2672EC"
    property string green               : "#267234"
    property string red                 : "#660000"
    property string iblue               : "#39aef9"
    property string grey                : "#e4e3e9"
    property string gray                : "#5e5d63"
    property string blanc               : "#fef8fb"

    property int    cacheBuff           : 65536

    signal sendMessage(string messageAEnvoyer, int id)
  
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
        color       : blanc 
        border.color: blanc
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
            font.family   : "GE Inspira"
            font.pointSize: 10
            color         : gray 
            text          : textInputSearch
            smooth        : true

            onAccepted:
            {
                sendMessage(textInput.text, 1)
                textInput.text  = ''
		idP = 1 
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
            width     : listViewSPS.width 
            //width       : listViewSPS.width - photo.width
            height      : nom.height + 14 
            clip        : true
            smooth      : true
            color       : (id == 2)?grey:iblue
            border.color: "transparent"
            border.width: 1
            radius      : 08
	    
            anchors
            {
               left        : listDelegateSPS.left
               leftMargin  : 50
	    }

	    Rectangle
	    {
               id    : photo
               width : 20
	       height: listViewSPS.height
	       clip  : true
               color : (id == 2)?"transparent":iblue
	       radius: 08 

               anchors
	       {
                  left  : parent.left
                  right : nom.left
	       }
	    }

            Text
            {
                id:nom

                anchors
                {
                   //left        : delegateItem.left
                   left          : photo.right
                   //leftMargin  : 10
                   right       : delegateItem.right
                   rightMargin : 5
                   verticalCenter: delegateItem.verticalCenter
                   topMargin     : 0
                   bottomMargin  : 0
                }

                text          : name 
                font.family   : "GE Inspira"
                font.pointSize: 10
                color         : (id == 1)?blanc:gray
                smooth        : true
                width         : parent.width
                wrapMode      : Text.WordWrap
                clip          : true
                textFormat    : Text.RichText

		//onLinkActivated: Qt.openUrl(link)
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
                     easing.type: Easing.OutBack
                 }
                 ColorAnimation
                 {
                     target   : delegateItem
                     property : "color"
                     to       : (id == 1)?iblue:grey 
                     duration : 300
                 }
                 NumberAnimation
                 {
                     target     : delegateItem;
                     property   : "scale";
                     from       : 0
                     to         : 1
                     duration   : 300
                     easing.type: Easing.OutBack
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
                        easing.type: Easing.OutBack
                    }
                    NumberAnimation
                    {
                        target     : delegateItem;
                        property   : "scale";
                        to         : 0
                        duration   : 300;
                        easing.type: Easing.OutBack
                    }
                    NumberAnimation
                    {
                        property    : "width";
                        duration    : 300
                        easing.type : Easing.OutBack
                    }
                }
            }
            Behavior on height
            {
                NumberAnimation
                {
                    property   : "height";
                    duration   : 300;
                    easing.type: Easing.OutBack
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
                easing.type: Easing.OutBack
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
       nomable : listViewSPS;
    }
    */
}
