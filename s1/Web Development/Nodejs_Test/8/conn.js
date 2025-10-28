const mysql = require('mysql2');
 
const con = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: '4442',
    database: 'CollegeDB'
});
 
con.connect((err) => {
    if (err) {
        console.error('Error connecting:', err.stack);
        return;
    }
    console.log('Connected to MySQL server');
 
    con.query('CREATE DATABASE IF NOT EXISTS CollegeDB', (err, result) => {
        if (err) throw err;
       
        con.end();
    });
});
module.exports=con;