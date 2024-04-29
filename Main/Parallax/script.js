let text = document.getElementById('text');
let leaf = document.getElementById('leaf');
let Montanhas = document.getElementById('hill2');
let Arvore = document.getElementById('hill4');
let hill5 = document.getElementById('hill5');

window.addEventListener('scroll', () => {
    let value= window.scrollY;

    text.style.marginTop = value * 2.5 + 'px';
    Arvore.style.left = value * -1.5 + 'px';
    Montanhas.style.top = value * 1 + 'px';
})