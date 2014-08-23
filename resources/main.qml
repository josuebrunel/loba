
// import QtQuick 1.0
import QtQml 2.0

Rectangle
{
   color : "black"
   height: 500
   width : 700
   smooth: true

   property string message : "";

   Image
   {
      width   : parent.width 
      height  : parent.height
      fillMode: Image.PreserveAspectCrop
      smooth  : true
      source  : "qrc:/images/wall.png"
   }

   Component
   {
      id    : listDelegateMessage
      width : listViewMessage.width
      height: 50
      clip  : true
      color : "#343434"
      
      Rectangle
      {
         id    : delegateItem
         width : listViewMessage.width
         height: listViewMessage.height
         clip  : true
         color : "#343434"   

         Text
         {
            id : messageItem

            anchors
            {
               left           : parent.left
               leftMargin     : 0
               vecticalCenter : parent.vecticalCenter
            }

            text : message
            color: "white"
         }
      }
   }

   ListView
   {
      id    : listViewMessage
      width : parent.width
      height: parent.height
      clip  : true
      
      anchors
      {
         left       : parent.left
         leftMargin : 20
         top        : parent.top
         topMargin  : 20
      }

      model    : myModelMessage
      delegate : listDelegateMessage
   }
}
