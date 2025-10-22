function validateForm(event) {
  event.preventDefault();

  let name = document.getElementById("name").value.trim();
  let email = document.getElementById("email").value.trim();
  let phone = document.getElementById("phone").value.trim();
  let password = document.getElementById("password").value.trim();
  let confirmPassword = document.getElementById("confirmPassword").value.trim();
  let memberType = document.getElementById("memberType").value;
  let error = document.getElementById("error-message");

  // Basic validation
  if (name === "" || email === "" || phone === "" || password === "" || confirmPassword === "" || memberType === "") {
    error.textContent = "All fields are required!";
    return false;
  }

  // Email validation
  let emailPattern = /^[^ ]+@[^ ]+\.[a-z]{2,3}$/;
  if (!email.match(emailPattern)) {
    error.textContent = "Please enter a valid email address!";
    return false;
  }

  // Phone validation
  let phonePattern = /^[0-9]{10}$/;
  if (!phone.match(phonePattern)) {
    error.textContent = "Phone number must be 10 digits!";
    return false;
  }

  // Password match
  if (password !== confirmPassword) {
    error.textContent = "Passwords do not match!";
    return false;
  }

  // Success → Redirect
  error.textContent = "";
  alert("Registration successful!");
  window.location.href = "success.html";
  return true;
}
