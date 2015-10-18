<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        else if (empty($_POST["confirmation"]))
        {
            apologize("You must provide your password confirmation.");
        }
        else if ($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Invalid password confirmation.");
        }
        
        //query database for inserting
        $result = query("INSERT INTO users (username,hash,cash) VALUES ( ?, ?, 10000.0000)",$_POST["username"],crypt($_POST["password"]));
    
        //control for errors(e.g.duplicate username)
        if ($result === false)
        {
            apologize("Error occurred while inserting username into database.(e.g.duplicate username)");
        }
        
        //get id
        $rows = query("SELECT LAST_INSERT_ID() AS id");
        $id = $rows[0]["id"];
        
        //store it
        $_SESSION["id"] = $id;
        
        //redirect to index.php
        redirect("index.php"); 
    }

?>
