const bookCards = document.querySelectorAll('.book-card');

bookCards.forEach(card => {
  card.addEventListener('click', () => {
    const availabilityDiv = card.querySelector('.book-availability');

    if (availabilityDiv.classList.contains('available')) {
      availabilityDiv.classList.remove('available');
      availabilityDiv.classList.add('checked-out');
      availabilityDiv.textContent = 'Checked Out';
    } else {
      availabilityDiv.classList.remove('checked-out');
      availabilityDiv.classList.add('available');
      availabilityDiv.textContent = 'Available';
    }
  });
});
