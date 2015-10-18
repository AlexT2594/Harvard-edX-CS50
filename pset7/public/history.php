<?php

    // configuration
    require("../includes/config.php");

    $rows = query("SELECT * from history WHERE id = ?",$_SESSION["id"]);

    render("history_t.php",["title" => "History","rows" => $rows]);
?>
