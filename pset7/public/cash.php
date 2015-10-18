<?php

    //config
    require("../includes/config.php");
    
    $transaction = "Deposit";

    if($_SERVER["REQUEST_METHOD"] != "POST" ){
        
        render("cash_form.php",["title" => "Add funds"]);
    
    }else{
        
        if(empty($_POST["cash"])){
            apologize("You must specify the amount of money you want to add.");
        }else if($_POST["cash"] > 10000){
            apologize("Your request exceeded the maximum amount allowed($10000).");
        }
        
        query("UPDATE users SET cash = cash + ? WHERE id = ?",$_POST["cash"],$_SESSION["id"]);
        query("INSERT INTO history (id,transaction,price) VALUES(?, ?, ?)",$_SESSION["id"],$transaction,$_POST["cash"]);
    
        redirect("/");
    }




?>
