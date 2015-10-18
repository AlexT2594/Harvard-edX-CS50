<ul class="nav nav-pills">
    <li><a href="cash.php">Add funds</a><li>
    <li><a href="quote.php">Quote</a></li>
    <li><a href="buy.php">Buy</a></li>
    <li><a href="sell.php">Sell</a></li>
    <li><a href="history.php">History</a></li>
    <li><a href="logout.php"><strong>Log Out</strong></a></li>
</ul>

<table class="table table-striped">
    <tr>
        <td><strong>Symbol</strong></td>
        <td><strong>Name</strong></td>
        <td><strong>Shares</strong></td>
        <td><strong>Price</strong></td>
        <td><strong>TOTAL</strong></td>
    </tr>
    <?php foreach($positions as $position): ?>
    
        <tr>
            <td><?= $position["symbol"] ?></td>
            <td><?= $position["name"] ?></td>
            <td><?= number_format($position["shares"],0) ?></td>
            <td><?="$".$position["price"] ?></td>
            <td><?="$".$position["current"] ?></td>
        </tr>
        
    <?php endforeach ?>
    <tr>
        <td>CASH</td>
        <td></td>
        <td></td>
        <td></td>
        <td><?="$".number_format($total,2,'.',',')?></td>
    </tr>
</table>
