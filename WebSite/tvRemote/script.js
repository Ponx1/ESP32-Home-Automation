const powerButton = document.getElementById('power');
const sourceButton = document.getElementById('source');
const volUpButton = document.getElementById('vol-up');
const volDownButton = document.getElementById('vol-down');

const sendCommand = command => {
	fetch('endpoint', {method: 'post', body: command});
}

const power = () => {
	console.log('power');
	sendCommand('power');
};

const source = () => {
	console.log('source');
	sendCommand('source');
};

const volUp = () => {
	console.log('volUp');
	sendCommand('volUp');
};

const volDown = () => {
	console.log('volDown');
	sendCommand('volDown');
};

powerButton.addEventListener('click', power);
sourceButton.addEventListener('click', source);
volUpButton.addEventListener('click', volUp);
volDownButton.addEventListener('click', volDown);