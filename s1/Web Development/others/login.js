 function validateLogin() {
      // Get form values
      const username = document.getElementById("username").value.trim();
      const password = document.getElementById("password").value.trim();

      // Simple validation
      if (username === "") {
        alert("Please enter your username.");
        return false;  // prevent form submission
      }

      if (password === "") {
        alert("Please enter your password.");
        return false;
      }

      // Example: password length check
      if (password.length < 6) {
        alert("Password must be at least 6 characters long.");
        return false;
      }

      // If all validations pass
      alert("Login successful!");  // just for demo
      return true;  // allow form submission
    }