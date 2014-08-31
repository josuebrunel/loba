/********************************************************
** 
** Copyright (C) 2014 godbod and/or its subsidiary (-ies)
** Contact : gkounkou@gmail.com
**
*********************************************************/

import QtQuick 1.1
import "."

Rectangle
{
   id    : chat
   height: 600
   width : 300

   property bool userFocus  : false 
   property bool loginFocus : false

   Loader
   {
      id           : loader
      anchors.fill : parent
      visible      : source != ""
   }   

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
      spacing         : 16
      visible         : !loader.visible 
       
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

            MouseArea
            {
               anchors.fill: parent
               onClicked:
               {
                  userFocus  = true 
                  loginFocus = false
               }
            }
            TextInput 
            {
               anchors.horizontalCenter:parent.horizontalCenter
               anchors.verticalCenter  :parent.verticalCenter
               focus : userFocus

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

            MouseArea
            {
               anchors.fill: parent
               onClicked:
               {
                  userFocus  = false 
                  loginFocus = true
               }
            }
            TextInput 
            {
               anchors.horizontalCenter:parent.horizontalCenter
               anchors.verticalCenter  :parent.verticalCenter
               echoMode: TextInput.Password 
               focus   : loginFocus

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
            radius: 3

            

            Text
            {
               anchors.horizontalCenter:parent.horizontalCenter
               anchors.verticalCenter  :parent.verticalCenter
               text   : "Login";
            }
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                   chat.state = "main" 
                }
            }
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
   Connections
   {
      target    : loader.source != "" ? loader.item : null
   }

   states : 
   [
      State
      {
         name : "main"
         PropertyChanges
         {
            target : loader
            source : "main.qml" 
         }
      }
   ]
}
