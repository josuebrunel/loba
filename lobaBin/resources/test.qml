import QtQuick 1.1

 Item {
     width: 200; height: 250
     visible:true

     ListModel {
         id: myModel
         ListElement { type: "Dog"; age: 8 }
         ListElement { type: "Cat"; age: 5 }
     }

     Component {
         id: myDelegate
         Text { text: type + ", " + age }
     }

     ListView {
         anchors.fill: parent
         model: myModel
         delegate: myDelegate
     }
 }
