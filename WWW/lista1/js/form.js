const form = document.querySelector('form');

form.addEventListener('submit', (event) => {
    event.preventDefault();

    const liczba = document.getElementById("difficulty").value;
    const zdjecie = document.getElementById("img").files[0];
    const reader = new FileReader();

    reader.onload = () => {
        const img = document.createElement("img");
        img.src = reader.result;
        document.body.appendChild(img);
    }

    reader.readAsDataURL(zdjecie);
});