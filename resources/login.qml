/********************************************************
** 
** Copyright (C) 2014 godbod and/or its subsidiary (-ies)
** Contact : gkounkou@gmail.com
**
*********************************************************/

import QtQuick 1.1

Rectangle
{
   id        : chat
   height    : 600
   width     : 300

   property bool userFocus  : false 
   property bool loginFocus : false
   property bool disp       : true
   property bool ndisp      : false

   signal sendLogin(string login, string password)
   signal quitLogin()

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
               id : login
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
               id : password
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
               id          : loginArea
               anchors.fill: parent
               onClicked   : 
               {
                  if (login.text.length != 0 && password.text.length != 0) {
                     // console.log(login.text)
                     // console.log(password.text)

                     sendLogin(user.text, passwd.text)
                     quitLogin()
                  }
               }
            }
         }
         Rectangle 
         {
            width   : 50
            height  : 20
            radius  : 3
            visible : disp

            Text
            {
               anchors.horizontalCenter:parent.horizontalCenter
               anchors.verticalCenter  :parent.verticalCenter
               text   : "Help ?";
            }
            //onClicked: console.log("help ?") 
         }
      }
   }

   Text
   {
      anchors.bottom          : parent.bottom
      anchors.horizontalCenter:parent.horizontalCenter
      anchors.bottomMargin    : 10
      text                    : "Copyright (C) 2014  godbod"
      color                   : "lightgrey"
   }
}
