function store(){
    const myObject = {
        name : "S Gayathri",
        age : 20,
        gender : "Female"
      }
      
      window.localStorage.setItem("myObject", JSON.stringify(myObject));
}

function timeTeller(){
    var time = new Date().toLocaleTimeString();
    alert(time);

}
function changer(){
    document.body.style.background = "yellow"
}
function refresher(){
    window.location.reload();

}
function newWin(){
    var strWindowFeatures = "location=yes,height=570,width=520,scrollbars=yes,status=yes";
    var URL = "https://www.google.com/";
    var win = window.open(URL, "_blank", strWindowFeatures);
}
function didIt(){
    var n = 600
    while(n!=0){
        console.log("I did it")
        n--;
    }
}