<?php

    // configuration
    require("../includes/config.php");
    
    $transaction = "SELL";
    
    if($_SERVER["REQUEST_METHOD"] != "POST"){
        $rows = query("SELECT * FROM stock_shares WHERE id = ?",$_SESSION["id"]);
        $symbols = array();
        
        foreach($rows as $row){
        array_push($symbols,$row["symbol"]); 
        }
        //sell_form
        render("sell_form.php",["title" => "Sell Form","symbols" => $symbols]);
    }
    else
    {
        $shares = query("SELECT shares FROM stock_shares WHERE id = ? AND symbol = ?",$_SESSION["id"],$_POST["symbol"]);
        
        $stock = lookup($_POST["symbol"]);
        
        $cash = $stock["price"] * $shares[0]["shares"];
        query("UPDATE users SET cash = cash + ? WHERE id = ?",$cash,$_SESSION["id"]);
        query("DELETE FROM stock_shares WHERE id = ? AND symbol = ?",$_SESSION["id"],$_POST["symbol"]);
        query("INSERT INTO history (id,transaction,symbol,shares,price) VALUES(?, ?, ?, ?, ?)",$_SESSION["id"],$transaction,$_POST["symbol"],$shares[0]["shares"],$stock["price"]);
        
        //redirect to index
        redirect("/");
    }
    
?>
