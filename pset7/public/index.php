<?php

    // configuration
    require("../includes/config.php");
    
    $rows = query("SELECT * FROM stock_shares WHERE id = ?",$_SESSION["id"]);
    $money = query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"]);
    $total = $money[0]["cash"];
    $positions = [];
    
    foreach ($rows as $row){
        $stock = lookup($row["symbol"]);
        if($stock !== false){
            $cash = $row["shares"] * $stock["price"];
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "current" => $cash
            ];
        }
    }
              

    // render portfolio
    render("portfolio.php", ["title => Portfolio","positions" => $positions ,"total" => $total]);

?>
