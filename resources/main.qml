import QtQuick 1.1

Rectangle
{
    id: container

    height: 600
    width : 300


    property bool   varVisibleSPSTitle  : true
    property bool   varVisibleSPS       : true
    property string nameP               : "Hello, welcome to NetCOM¹ 2014"
    property bool   textTypeSearch      : true
    property bool   focusSearch         : false
    property string textInputSearch     : "tap your message..."
    property int    index               : 1

    signal sendMessage(string messageAEnvoyer);

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
            font.pixelSize: 11
            color         : "black"
            text          : textInputSearch

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
            height      : (name.length*8)>(listViewSPS.width)?60:30 
            clip        : true
            smooth      : true
            color       : "#2672EC"
            border.color: "black"
            border.width: 0
            radius      : 5

            y: listViewSPS.currentItem.y

            Behavior on y 
            {
               SpringAnimation 
               {
                  spring : 3
                  damping: 0.2
               }
            }

            Text
            {
                id:nom
                anchors
                {
                    left:parent.left
                    leftMargin: 7
                    verticalCenter: parent.verticalCenter
                }

                text          : name 
                font.family   : "Garamont"
                font.pixelSize: 13
                color         : "white"
                smooth        : true
            }

            Rectangle
            {
                id           : rec
                color        : "#c0c0c0"
                height       : delegateItem.height
                width        : delegateItem.width
                border.color : "black"
                border.width : 0
                opacity      : 0.2
                radius       : 5
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
                     //to       : 30
                     to         : (name.length*8)>(listViewSPS.width)?60:30 
                     duration   : 500;
                     easing.type: Easing.InOutBack
                 }
                 ColorAnimation
                 {
                     target   : delegateItem
                     property : "color"
                     to       :"#2672EC"
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
                        duration    : 1000
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
        cacheBuffer: 10
        visible    : varVisibleSPS
        spacing    : 10
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

        model   : myModelsps
        delegate: listDelegateSPS
    }
}
