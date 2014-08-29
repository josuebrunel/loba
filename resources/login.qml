/********************************************************
** 
** Copyright (C) 2014 godbod and/or its subsidiary (-ies)
** Contact : gkounkou@gmail.com
**
*********************************************************/

import QtQuick 1.1

Rectangle
{
   id    : chat

   height: 600
   width : 300

    Image
    {
        id      : wallpaper
        height  : parent.height
        width   : parent.width
        fillMode: Image.PreserveAspectCrop
        source  : "wallpaper.jpg"
        smooth  : true
    }
   
    Column
    {
       anchors.centerIn: parent
       spacing: 16
       
       Column
       {
          spacing: 4
          Text
          {
             text          : "Username" 
             font.family   : "Helvetica"
             font.pointSize: 12
             color         : "white"
             anchors.horizontalCenter:user.horizontalCenter
          }

          Rectangle
          {
             id           : user
             border.width : 1
             border.color : "white"
             width        : 160
             height       : 20
             radius       : 2

             TextInput 
             {
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.verticalCenter  :parent.verticalCenter
                focus   : true
             }
          }
       }

       Column 
       {
          spacing : 10

          anchors.centerIn:parent.Center 

          Text 
          { 
             text          : "Password" 
             font.family   : "Helvetica"
             font.pointSize: 12
             color         : "white"
             anchors.horizontalCenter:passwd.horizontalCenter
          }

          Rectangle
          {
             id           : passwd
             border.width : 1
             border.color : "white"
             width        : 160
             height       : 20
             radius       : 2

             TextInput 
             {
                focus   : true
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.verticalCenter  :parent.verticalCenter
                echoMode: TextInput.Password 
             }
          }
       }
       Row 
       {
          spacing: 16
          anchors.horizontalCenter: parent.horizontalCenter

          Rectangle
          { 
             width : 50
             height: 20
             radius : 3

             Text
             {
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.verticalCenter  :parent.verticalCenter
                text   : "Login";
             }
             //onClicked: console.log("login") 
          }
          Rectangle 
          {
             width : 50
             height: 20
             radius : 3

             Text
             {
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.verticalCenter  :parent.verticalCenter
                text   : "Guest";
             }
             //onClicked: console.log("guest") 
          }
       }
    }
}
