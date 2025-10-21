function validation() {
    let name = document.getElementById("fname").value.trim();
    let age = document.getElementById("age").value.trim();
    let gender = document.getElementById("gender").value.trim();
    let email = document.getElementById("email").value.trim();
    let pnumber = document.getElementById("pnumber").value.trim();
    let password = document.getElementById("password").value.trim();
    let confirmPass = document.getElementById("confirm").value.trim();

    if (name === "") {
        Swal.fire({
            icon: 'warning',
            title: 'Oops...',
            text: 'Please enter your name',
        });
        return false;
    }

    if (age === "") {
        Swal.fire({
            icon: 'warning',
            title: 'Oops...',
            text: 'Enter your age',
        });
        return false;
    } else if (isNaN(age) || age <= 0) {
        Swal.fire({
            icon: 'warning',
            title: 'Oops...',
            text: 'Please enter a valid age',
        });
        return false;
    }

    if (gender === "") {
        Swal.fire({
            icon: 'warning',
            title: 'Oops...',
            text: 'Please enter your gender',
        });
        return false;
    }

    if (email === "") {
        Swal.fire({
            icon: 'warning',
            title: 'Oops...',
            text: 'Enter your email',
        });
        return false;
    } else {
        let emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        if (!emailPattern.test(email)) {
            Swal.fire({
                icon: 'error',
                title: 'Invalid Email',
                text: 'Please enter a valid email address',
            });
            return false;
        }
    }

    if (pnumber === "") {
        Swal.fire({
            icon: 'warning',
            title: 'Oops...',
            text: 'Please enter your phone number',
        });
        return false;
    } else if (!/^\d{7,15}$/.test(pnumber)) {
        Swal.fire({
            icon: 'error',
            title: 'Invalid Phone Number',
            text: 'Please enter a valid phone number (7-15 digits)',
        });
        return false;
    }

    if (password === "") {
        Swal.fire({
            icon: 'warning',
            title: 'Oops...',
            text: 'Enter your password',
        });
        return false;
    }

    if (confirmPass === "") {
        Swal.fire({
            icon: 'warning',
            title: 'Oops...',
            text: 'Confirm your password',
        });
        return false;
    }
}