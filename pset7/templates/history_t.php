<table class="table table-striped">
    <tr>
        <td><strong>Transaction</strong></td>
        <td><strong>Date/Time</strong></td>
        <td><strong>Symbol</strong></td>
        <td><strong>Shares</strong></td>
        <td><strong>Price</strong></td>
    </tr>
    <?php foreach($rows as $row): ?>
    
        <tr>
            <td><?= $row["transaction"] ?></td>
            <td><?= $row["time"] ?></td>
            <td><?= $row["symbol"] ?></td>
            <td><?= number_format($row["shares"],0) ?></td>
            <td><?="$".number_format($row["price"],2) ?></td>
        </tr>
        
    <?php endforeach ?>
</table>
