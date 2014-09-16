import QtQuick 1.1

Rectangle 
{
    id                 : container
    width              : 300
    height             : 300
    property bool disp : false
 
    Rectangle 
    {
        id    : rect
        width : 100
        height: 100
        color : "red"
 
        MouseArea 
        {
           id          : mouseArea
           anchors.fill: parent
           onClicked   : 
           {
              disp = !disp
           }
        }
        Loader 
        {
            id : pageLoad
        }
 
        states: State 
        {
           name : "resized"
           when : disp

           PropertyChanges 
           { 
              target   : rect; 
              color    : "blue"
              //height : container.height 
           }
           PropertyChanges
           { 
              target : pageLoad
              source : "test.qml"
              x      : 200
              y      : 100
           }
        }
    }
}
