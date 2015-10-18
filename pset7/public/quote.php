<?php

    //configuration
    require("../includes/config.php");
    
    if( $_SERVER["REQUEST_METHOD"] != "POST"){
    //quote_form
    render("quote_form.php");
    }
    else
    {

    //look up a stock's latest price
    $stock = lookup($_POST["symbol"]);
    
    //control valid symbol
    if($stock === false)
    {
        apologize("Invalid stock symbol.");
    }
    
    $money = $stock["price"];
    
    //display stock's latest price
    render("quote_t.php",["title" => "Quote","price" => $money,"name" => $stock["name"],"symbol" => $stock["symbol"]]);
    }
?>
