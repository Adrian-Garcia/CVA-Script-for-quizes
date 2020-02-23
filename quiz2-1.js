$('#check1').on('click', function() {

	let responses = $('.quest1');

	for (let i=0; i<responses.length; i++) {

		if (responses[i].checked && responses[i].value == '1') {
			alert('¡Correcto!');
		}

		else if (responses[i].checked) {
			alert('Incorrecto');
		}
	}
});

$('#check2').on('click', function() {

	let responses = $('.quest2');

	for (let i=0; i<responses.length; i++) {

		if (responses[i].checked && responses[i].value == '1') {
			alert('¡Correcto!');
		}

		else if (responses[i].checked) {
			alert('Incorrecto');
		}
	}
});

$('#check3').on('click', function() {

	let responses = $('.quest3');

	for (let i=0; i<responses.length; i++) {

		if (responses[i].checked && responses[i].value == '1') {
			alert('¡Correcto!');
		}

		else if (responses[i].checked) {
			alert('Incorrecto');
		}
	}
});

