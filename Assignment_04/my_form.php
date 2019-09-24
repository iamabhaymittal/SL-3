<!DOCTYPE HTML>
<html>

<head>
  <style>
    .error {
      color: #FF0000;
    }

    input {
      padding: 1px;
      font-size: 20px;
      border-radius: 25px;
    }

    input[type=submit] {
      background-color: #4CAF50;
      border-radius: 25px;
      padding: 15px;
    }
  </style>
</head>

<header style="background-color: black">

  <body style="background-color: lightblue;">

    <a href="main.html"><img src="pa.png" width="100" height="100"></a>
    <font size="7" style="font-family: verdana" color="lightblue"><big><big>&nbsp; PC Assembler&nbsp;</big></big>&nbsp;
      <small><small><small><small><a href="laptops.html" style="color: lightblue;text-decoration:none;"> Laptops </a>
              &nbsp;&nbsp;<a href="1.html" style="color: lightblue;text-decoration:none;"> Build a PC </a>
              &nbsp;&nbsp;<a href="recommends.html" style="color: lightblue;text-decoration:none;"> Recommended Rigs</a>
              &nbsp;&nbsp;<a href="signup.html" style="color: lightblue;text-decoration:none;"> Login/Register</a>

            </small></small></small></small></font>


</header>

<center>
  <?php
  // define variables and set to empty values
  $nameErr = $emailErr = $websiteErr = "";
  $name = $email =  $website = "";

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (empty($_POST["name"])) {
      $nameErr = "Name is required";
    } else {
      $name = test_input($_POST["name"]);
      // check if name only contains letters and whitespace
      if (!preg_match("/^[a-zA-Z ]*$/", $name)) {
        $nameErr = "Only letters and white space allowed";
      }
    }

    if (empty($_POST["email"])) {
      $emailErr = "Email is required";
    } else {
      $email = test_input($_POST["email"]);
      // check if e-mail address is well-formed
      if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $emailErr = "Invalid email format";
      }
    }

    if (empty($_POST["website"])) {
      $website = "";
    } else {
      $website = test_input($_POST["website"]);
      // check if URL address syntax is valid (this regular expression also allows dashes in the URL)
      if (!preg_match("/\b(?:(?:https?|ftp):\/\/|www\.)[-a-z0-9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%=~_|]/i", $website)) {
        $websiteErr = "Invalid URL";
      }
    }
  }

  function test_input($data)
  {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
  }
  ?>

  <h2>PHP Form Validation (Assignment 4)</h2>
  <p><span class="error">* required field</span></p>
  <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Name: <input type="text" name="name" value="<?php echo $name; ?>">
    <span class="error">* <br><?php echo $nameErr; ?></span>
    <br><br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;E-mail: <input type="text" name="email" value="<?php echo $email; ?>">
    <span class="error">* <br><?php echo $emailErr; ?></span>
    <br><br>
    Website: <input type="text" name="website" value="<?php echo $website; ?>">
    <span class="error"><?php echo $websiteErr; ?></span>
    <br><br>

    <input type="submit" name="submit" value="Submit">
  </form>

  <?php
  echo "<h2>Inputs:</h2>";
  echo $name;
  echo "<br>";
  echo $email;
  echo "<br>";
  echo $website;

  ?>
</center>
</body>


</html>
