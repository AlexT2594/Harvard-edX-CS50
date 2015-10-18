<?php

    // configuration
    require("../includes/config.php");
    
    $transaction = "BUY";
    
    if($_SERVER["REQUEST_METHOD"] != "POST"){
    
        render("buy_form.php",["title"=>"Buy"]);
    
    }else{
        if(empty($_POST["symbol"])){
            apologize("You must specify a stock to buy.");
        }else if(empty($_POST["shares"])){
            apologize("You must specify a number of shares.");
        }else if(!preg_match("/^\d+$/", $_POST["shares"])){
            apologize("Invalid number of shares.");
        }
        $stock = lookup($_POST["symbol"]);
        if($stock === false){
            apologize("Invalid stock symbol");
        }
        $rows = query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"]);
        $cash = $rows[0]["cash"];
    
        $cost = $stock["price"] * $_POST["shares"];
        if($cash < $cost){
            apologize("Non-sufficient funds.");
        }
        $_POST["symbol"] = strtoupper($_POST["symbol"]);
        query("INSERT INTO stock_shares (id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)",$_SESSION["id"],$_POST["symbol"],$_POST["shares"]);
    
        query("UPDATE users SET cash = cash - ? WHERE id = ?",$cost,$_SESSION["id"]);
        
        query("INSERT INTO history (id,transaction,symbol,shares,price) VALUES(?, ?, ?, ?, ?)",$_SESSION["id"],$transaction,$_POST["symbol"],$_POST["shares"],$stock["price"]);
        
        redirect("/");
    }
    
    
    


?>
