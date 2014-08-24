import QtQuick 1.1

Rectangle
{
    id: container

    height: 600
    width : 800


    property bool   varVisibleSPSTitle  : true
    property bool   varVisibleSPS       : true
    property string name                : "Welcome on godbod Chatter 2014 !"

    Image
    {
        id      : wallpaper
        height  : parent.height
        width   :  parent.width
        fillMode: Image.Stretch
        source  : "wallpaper.png"
        smooth  : true
        
    }

    Component
    {
        id: listDelegateSPS

        Rectangle
        {
            id:delegateItem

            width       : listViewSPS.width
            height      : 30
            clip        : true
            smooth      : true
            color       : "#343434"
            border.color: "black"
            border.width: 0
            radius      : 5

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
                font.family   : "Monospace"
                font.pixelSize: 13
                color         : "white"
                smooth        : true
            }

            Rectangle
            {
                id           : rec
                color        : "#c0c0c0"
                height       : delegateItem.height+1
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
                     to         : 70;
                     duration   : 700;
                     easing.type: Easing.InOutBack
                 }
                 ColorAnimation
                 {
                     target   : delegateItem
                     property : "color"
                     to       :"brown"
                     duration : 700
                 }
                 NumberAnimation
                 {
                     target     : delegateItem;
                     property   : "scale";
                     from       : 0
                     to         : 1
                     duration   : 700
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
        width      : parent.width/2
        height     : parent.height
        clip       : true
        opacity    : 1
        cacheBuffer: 10
        visible    :varVisibleSPS

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
            left      : parent.left
            leftMargin: 20
            top       : parent.top
            topMargin : 50
        }

        model   : myModelsps
        delegate: listDelegateSPS
    }
}
