const form = document.querySelector('form');

form.addEventListener('submit', (event) => {
  event.preventDefault(); // zapobieganie domyślnemu zachowaniu formularza
  
  // Pobranie wybranego rozmiaru planszy
  const rozmiar = document.querySelector('#rozmiar').value;
  
  // Pobranie wybranego zdjęcia
  const zdjecie = document.querySelector('#zdjecie').files[0];
  
  // Wyświetlenie wybranego rozmiaru i zdjęcia w konsoli
  console.log(`Wybrany rozmiar planszy: ${rozmiar}`);
  PUZZLE_DIFFICULTY = rozmiar;
  console.log(`Wybrane zdjęcie: ${zdjecie.name}`);
  _img.src = zdjecie.name;
  
  // Przygotowanie do wysłania danych na serwer (tutaj kod wysyłający formularz na serwer)
});