#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


struct Question {
	string text;
	vector<string> phrases;
};

// Main program
int main() {

	ifstream inputFile;
	ofstream htmlFile;
	ofstream jsFile;

	string htmlFileName;
	string jsFileName;
	string line;

	Question question;

	bool newFile = false;
	bool questions = false;

	int counter = 0;
	int itteration = 0;
	int numQuestion = 1;

	inputFile.open("inputFile.txt");

	while (!inputFile.eof()) {

		getline(inputFile, line);

		// Beggining of a new file
		if (line == "-") {

			questions = false;
			newFile = true;

			if (itteration > 0) {

				cout << question.text << endl;

				for (int i=0; i<question.phrases.size(); i++) {
					cout << question.phrases[i] << endl;
				}

				htmlFile << "										<div class='row text-center'>" << endl;
				htmlFile << "											<div class='col'>" << endl;
				htmlFile << "												<div class='mrg-top-40'>" << endl;
				htmlFile << "													<a href='modulo1-origen-plagas.html' class='btn btn-info no-mrg-btm'>Regresar</a>" << endl;
				htmlFile << "												</div>" << endl;
				htmlFile << "											</div>" << endl;
				htmlFile << "										</div>" << endl;
				htmlFile << "										" << endl;
				htmlFile << "								</form>" << endl;
				htmlFile << "" << endl;
				htmlFile << "							</div>" << endl;
				htmlFile << "					  </div>" << endl;
				htmlFile << "					  <!-- Content Wrapper END -->" << endl;
				htmlFile << "" << endl;
				htmlFile << "					  <!-- Footer START -->" << endl;
				htmlFile << "					<footer class='content-footer'>" << endl;
				htmlFile << "							<div class='footer'>" << endl;
				htmlFile << "								<div class='row'>" << endl;
				htmlFile << "									<div class='col-8'>" << endl;
				htmlFile << "										<p>Se prohíbe la reproducción total o parcial sin previo y expreso consentimiento por escrito.</p>" << endl;
				htmlFile << "										<p>D.R.© Instituto Tecnológico y de Estudios Superiores de Monterrey, México, 2019.</p>" << endl;
				htmlFile << "									</div>  " << endl;
				htmlFile << "									<div class='col-4 center align-self-center'>" << endl;
				htmlFile << "										<a href='http://videolabtec.itesm.mx/aviso-legal' target='_blank'>Aviso Legal</a>" << endl;
				htmlFile << "										<span><b>|</b></span>" << endl;
				htmlFile << "										<a href='https://tec.mx/es/avisos-de-privacidad' target='_blank'>Aviso de Privacidad</a>" << endl;
				htmlFile << "										<span><b>|</b></span>" << endl;
				htmlFile << "										<a href='../creditos.html'>Créditos</a>" << endl;
				htmlFile << "									</div>" << endl;
				htmlFile << "								</div>" << endl;
				htmlFile << "							</div>" << endl;
				htmlFile << "						</footer>" << endl;
				htmlFile << "						<!-- Footer END -->" << endl;
				htmlFile << "" << endl;
				htmlFile << "				  </div>" << endl;
				htmlFile << "				  <!-- Page Container END -->" << endl;
				htmlFile << "				</div>" << endl;
				htmlFile << "		</div>" << endl;
				htmlFile << "" << endl;
				htmlFile << "		<!-- build:js assets/js/vendor.js -->" << endl;
				htmlFile << "		<!-- plugins js -->" << endl;
				htmlFile << "		<script src='../../assets/vendors/jquery/dist/jquery.min.js'></script>" << endl;
				htmlFile << "		<script src='../../assets/js/recycled/navigationbar.js'></script>" << endl;
				htmlFile << "		<script src='../../assets/vendors/popper.js/dist/umd/popper.min.js'></script>" << endl;
				htmlFile << "		<script src='../../assets/vendors/bootstrap/dist/js/bootstrap.js'></script>" << endl;
				htmlFile << "	  <script src='../../assets/vendors/PACE/pace.min.js'></script>" << endl;
				htmlFile << "		<script src='../../assets/vendors/perfect-scrollbar/js/perfect-scrollbar.jquery.js'></script>" << endl;
				htmlFile << "" << endl;
				htmlFile << "		<script src='../../assets/js/progressbar.js'></script>" << endl;
				htmlFile << "" << endl;
				htmlFile << "		<!-- endbuild -->" << endl;
				htmlFile << "" << endl;
				htmlFile << "		<!-- build:js assets/js/app.min.js -->" << endl;
				htmlFile << "		<!-- core js -->" << endl;
				htmlFile << "		<script src='../../assets/js/app.js'></script>" << endl;
				htmlFile << "		<!-- <script src='../../assets/js/quizes/quiz-origen-plagas.js'></script> -->" << endl;
				htmlFile << "		<script src='../../assets/js/quizes/" << jsFileName << "'></script>" << endl;
				htmlFile << "" << endl;
				htmlFile << "		<script src='../../assets/js/progreso.js'></script>" << endl;
				htmlFile << "		<!--Aqui se pone el porcentaje completado,se puedo pasar como una division de (numero de paginas/total de paginas)-->" << endl;
				htmlFile << "		<script type='text/javascript'>show(.5)</script>" << endl;
				htmlFile << "" << endl;
				htmlFile << "		<!-- endbuild -->" << endl;
				htmlFile << "" << endl;
				htmlFile << "		<!-- Insert your dependencies here -->" << endl;
				htmlFile << "" << endl;
				htmlFile << "	</body>" << endl;
				htmlFile << "</html>" << endl;


				questions = false;
				question.text = "";
				question.phrases.clear();
				numQuestion = 0;
				htmlFileName = "";
				jsFileName = "";

				htmlFile.close();
				jsFile.close();
			}
		}

		// If the new file arrived previously, program take file names
		else if (newFile) {
			
			if (counter == 0) {
				
				htmlFileName = line;
				counter++;
			}

			else if (counter == 1) {

				jsFileName = line;
				counter = 0;
				newFile = false;

				htmlFile.open(htmlFileName.c_str());
				jsFile.open(jsFileName.c_str());
			}
		}

		// Beggining of questions
		else if (line == "$") {

			cout << htmlFileName << " " << jsFileName << endl;
			questions = true;

			htmlFile << "<!DOCTYPE html>" << endl;
			htmlFile << "<html>" << endl;
			htmlFile << "	<head>" << endl;
			htmlFile << "		<meta charset='utf-8'>" << endl;
			htmlFile << "		<meta name='viewport' content='width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no, shrink-to-fit=no'>" << endl;
			htmlFile << "		<title>Actividad de repaso | CVA - Centro Virtual de Aprendizaje</title>" << endl;
			htmlFile << "" << endl;
			htmlFile << "		<!-- Favicon -->" << endl;
			htmlFile << "		<link rel='shortcut icon' href='../../assets/images/logo/favicon.png'>" << endl;
			htmlFile << "" << endl;
			htmlFile << "		<!-- plugins css -->" << endl;
			htmlFile << "		<link rel='stylesheet' href='../../assets/vendors/bootstrap/dist/css/bootstrap.css' />" << endl;
			htmlFile << "		<link rel='stylesheet' href='../../assets/vendors/PACE/themes/blue/pace-theme-minimal.css' />" << endl;
			htmlFile << "		<link rel='stylesheet' href='../../assets/vendors/perfect-scrollbar/css/perfect-scrollbar.min.css' />" << endl;
			htmlFile << "" << endl;
			htmlFile << "		<!-- page plugins css -->" << endl;
			htmlFile << "" << endl;
			htmlFile << "		<!-- core css -->" << endl;
			htmlFile << "		<link href='../../assets/css/ei-icon.css' rel='stylesheet'>" << endl;
			htmlFile << "		<link href='../../assets/css/themify-icons.css' rel='stylesheet'>" << endl;
			htmlFile << "		<link href='../../assets/css/font-awesome.min.css' rel='stylesheet'>" << endl;
			htmlFile << "		<link href='../../assets/css/animate.min.css' rel='stylesheet'>" << endl;
			htmlFile << "		<link href='../../assets/css/app.css' rel='stylesheet'>" << endl;
			htmlFile << "		<link href='../../assets/css/progress.css' rel='stylesheet'>" << endl;
			htmlFile << "		<link href='../../assets/css/progreso.css' rel='stylesheet'>" << endl;
			htmlFile << "" << endl;
			htmlFile << "	</head>" << endl;
			htmlFile << "" << endl;
			htmlFile << "	<body class='header-info side-nav-dark'>" << endl;
			htmlFile << "		<div class='app'>" << endl;
			htmlFile << "			<div class='layout'>" << endl;
			htmlFile << "				<!-- Side Nav START -->" << endl;
			htmlFile << "				<div class='side-nav' id='sideNav'>" << endl;
			htmlFile << "					<div class='side-nav-inner'>" << endl;
			htmlFile << "						<div class='side-nav-logo'>" << endl;
			htmlFile << "							<a href='http://www.centroscomunitariosdeaprendizaje.org.mx/' target='_blank'>" << endl;
			htmlFile << "								<div class='logo logo-dark' style='background-image: url(" << '"' << "../../assets/images/logo/logo.png" << '"' << ")'></div>" << endl;
			htmlFile << "								<div class='logo logo-white' style='background-image: url(" << '"' << "../../assets/images/logo/logo.png" << '"' << ")'></div>" << endl;
			htmlFile << "							</a>" << endl;
			htmlFile << "							<div class='mobile-toggle side-nav-toggle'>" << endl;
			htmlFile << "								<a href=''>" << endl;
			htmlFile << "									<i class='ti-arrow-circle-left'></i>" << endl;
			htmlFile << "								</a>" << endl;
			htmlFile << "							</div>" << endl;
			htmlFile << "						</div>" << endl;
			htmlFile << "						<!--Inician contenidos laterales-->" << endl;
			htmlFile << "						<ul class='side-nav-menu scrollable'>" << endl;
			htmlFile << "							<li class='nav-item active'>" << endl;
			htmlFile << "								<a class='mrg-top-30' href='../../index.html'>" << endl;
			htmlFile << "									<span class='icon-holder'>" << endl;
			htmlFile << "										<i class='ti-home'></i>" << endl;
			htmlFile << "									</span>" << endl;
			htmlFile << "									<span class='title'>Inicio</span>" << endl;
			htmlFile << "								</a>" << endl;
			htmlFile << "							</li>" << endl;
			htmlFile << "							<li class='nav-item active'>" << endl;
			htmlFile << "								<a href='../introduccion.html'>" << endl;
			htmlFile << "									<span class='icon-holder'>" << endl;
			htmlFile << "										<i class='ei-foggy'></i>" << endl;
			htmlFile << "									</span>" << endl;
			htmlFile << "									<span class='title'>Introducción</span>" << endl;
			htmlFile << "								</a>" << endl;
			htmlFile << "							</li>  " << endl;
			htmlFile << "							<li class='nav-item dropdown'>" << endl;
			htmlFile << "								<a class='dropdown-toggle' href='javascript:void(0);'>" << endl;
			htmlFile << "									<span class='icon-holder'>" << endl;
			htmlFile << "										<i class='ti-agenda'></i>" << endl;
			htmlFile << "									</span>" << endl;
			htmlFile << "									<span class='title'>Temas</span>" << endl;
			htmlFile << "									<span class='arrow'>" << endl;
			htmlFile << "										<i class='ti-angle-right'></i>" << endl;
			htmlFile << "									</span>" << endl;
			htmlFile << "								</a>" << endl;
			htmlFile << "								<ul class='dropdown-menu'>" << endl;
			htmlFile << "										<li>" << endl;
			htmlFile << "											<a href='../temario-general.html' class='side-index-general'>Temario General</a>" << endl;
			htmlFile << "										</li>" << endl;
			htmlFile << "									<!-- Tema 1 -->" << endl;
			htmlFile << "									<li class='nav-item dropdown'>" << endl;
			htmlFile << "										<a class='dropdown-toggle' href='javascript:void(0);'>" << endl;
			htmlFile << "											<span class='title side-index-general'>Tema 1: Control <br>biológico</span>" << endl;
			htmlFile << "											<span class='arrow'>" << endl;
			htmlFile << "												<i class='ti-angle-right'></i>" << endl;
			htmlFile << "											</span>" << endl;
			htmlFile << "										</a>" << endl;
			htmlFile << "										<ul class='dropdown-menu'>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema1/tema1-origen-plagas.html' class='side-index-general'>Tema 1.1: Origen de las plagas</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema1/tema1-control-biologico.html' class='side-index-general'>Tema 1.2: Control biológico</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema1/tema1-enemigos-naturales-plagas.html' class='side-index-general'>Tema 1.3: Enemigos naturales de las plagas</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema1/tema1-control-biologico-ejemplo-mexico.html' class='side-index-general'>Tema 1.4: Ejemplo en México de control biológico</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema1/tema1-consideraciones-control-biologico.html' class='side-index-general'>Tema 1.5: Consideraciones del control biológico</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema1/tema1-ejemplo-agentes-control-biologico.html' class='side-index-general'>Tema 1.6: Ejemplos de agentes de control biológico</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema1/tema1-reglas-uso-parasitoides-depredadores.html' class='side-index-general'>Tema 1.7: Reglas para el uso de parasitoides y depredadores</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "										</ul>" << endl;
			htmlFile << "									</li>" << endl;
			htmlFile << "" << endl;
			htmlFile << "									<!-- Tema 2 -->" << endl;
			htmlFile << "									<li class='nav-item dropdown'>" << endl;
			htmlFile << "										<a class='dropdown-toggle' href='javascript:void(0);'>" << endl;
			htmlFile << "											<span class='title side-index-general'>Tema 2: Enemigos <br>de los bosques</span>" << endl;
			htmlFile << "											<span class='arrow'>" << endl;
			htmlFile << "												<i class='ti-angle-right'></i>" << endl;
			htmlFile << "											</span>" << endl;
			htmlFile << "										</a>" << endl;
			htmlFile << "										<ul class='dropdown-menu'>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema2/tema2-plagas.html' class='side-index-general'>Tema 2.1: Las plagas</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema2/tema2-incendios-forestales.html' class='side-index-general'>Tema 2.2: Incendios forestales</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema2/tema2-prevencion-incendios.html' class='side-index-general'>Tema 2.3: Prevención de incendios</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "										</ul>" << endl;
			htmlFile << "									</li>" << endl;
			htmlFile << "" << endl;
			htmlFile << "									<!-- Tema 3 -->" << endl;
			htmlFile << "									<li class='nav-item dropdown'>" << endl;
			htmlFile << "										<a class='dropdown-toggle' href='javascript:void(0);'>" << endl;
			htmlFile << "											<span class='title side-index-general'>Tema 3: <br>Reforestación</span>" << endl;
			htmlFile << "											<span class='arrow'>" << endl;
			htmlFile << "												<i class='ti-angle-right'></i>" << endl;
			htmlFile << "											</span>" << endl;
			htmlFile << "										</a>" << endl;
			htmlFile << "										<ul class='dropdown-menu'>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema3/tema3-bosque-y-cuidados.html' class='side-index-general'>Tema 3.1: El bosque y sus cuidados</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema3/tema3-semillero-almacigo.html' class='side-index-general'>Tema 3.2: El semillero de Almácigo</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema3/tema3-guia-establecimiento-reforestacion.html' class='side-index-general'>Tema 3.3: Guía para el establecimiento y cuidados de una reforestación</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema3/tema3-caracteristicas-suelo-clima.html' class='side-index-general'>Tema 3.4: Características del suelo y el clima</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema3/tema3-eucalipto.html' class='side-index-general'>Tema 3.5: Eucalipto, ejemplo de un árbol ideal para reforestar</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema3/tema3-otros-beneficios-eucalipto.html' class='side-index-general'>Tema 3.6: Otros beneficios de reforestar con eucalipto</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema3/tema3-agave-guanajuato.html' class='side-index-general'>Tema 3.7: Agave en el estado de Guanajuato</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema3/tema3-agave-perspectivas.html' class='side-index-general'>Tema 3.8: Agave en Guanajuato: Perspectivas</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "										</ul>" << endl;
			htmlFile << "									</li>" << endl;
			htmlFile << "" << endl;
			htmlFile << "									<!-- Tema 4 -->" << endl;
			htmlFile << "									<li class='nav-item dropdown'>" << endl;
			htmlFile << "										<a class='dropdown-toggle' href='javascript:void(0);'>" << endl;
			htmlFile << "											<span class='title side-index-general'>Tema 4: Utilización racional</span>" << endl;
			htmlFile << "											<span class='arrow'>" << endl;
			htmlFile << "												<i class='ti-angle-right'></i>" << endl;
			htmlFile << "											</span>" << endl;
			htmlFile << "										</a>" << endl;
			htmlFile << "										<ul class='dropdown-menu'>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema4/tema4-barreras-rompeviento.html' class='side-index-general'>Tema 4.1: Barreras rompeviento</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema4/tema4-errores-explotar-bosques.html' class='side-index-general'>Tema 4.2: Errores al explotar los bosques</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema4/tema4-razones-irracionales.html' class='side-index-general'>Tema 4.3: Razones irracionales para explotar los bosques</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema4/tema4-acciones-cuidado-bosques.html' class='side-index-general'>Tema 4.4: Acciones para cuidar los bosques</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema4/tema4-cuidados-adicionales-bosques.html' class='side-index-general'>Tema 4.5: Cuidados adicionales de los bosques</a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "											<li>" << endl;
			htmlFile << "												<a href='../tema4/tema4-reflexion.html' class='side-index-general'>Tema 4.6: Reflexión final </a>" << endl;
			htmlFile << "											</li>" << endl;
			htmlFile << "										</ul>" << endl;
			htmlFile << "									</li>" << endl;
			htmlFile << "								</ul>" << endl;
			htmlFile << "							</li>" << endl;
			htmlFile << "							<li class='nav-item active'>" << endl;
			htmlFile << "								<a href='../politicas.html'>" << endl;
			htmlFile << "									<span class='icon-holder'>" << endl;
			htmlFile << "										<i class='ei-human-resources'></i>" << endl;
			htmlFile << "									</span>" << endl;
			htmlFile << "									<span class='title'>Políticas</span>" << endl;
			htmlFile << "								</a>" << endl;
			htmlFile << "							</li>" << endl;
			htmlFile << "							<li class='nav-item active'>" << endl;
			htmlFile << "								<a href='../contacto.html'>" << endl;
			htmlFile << "									<span class='icon-holder'>" << endl;
			htmlFile << "										<i class='ei-phone-call'></i>" << endl;
			htmlFile << "									</span>" << endl;
			htmlFile << "									<span class='title'>Contáctanos</span>" << endl;
			htmlFile << "								</a>" << endl;
			htmlFile << "							</li>" << endl;
			htmlFile << "							<li class='nav-item active'>" << endl;
			htmlFile << "								<a href='../creditos.html'>" << endl;
			htmlFile << "									<span class='icon-holder'>" << endl;
			htmlFile << "										<i class='ei-clapperboard'></i>" << endl;
			htmlFile << "									</span>" << endl;
			htmlFile << "									<span class='title'>Créditos</span>" << endl;
			htmlFile << "								</a>" << endl;
			htmlFile << "							</li>" << endl;
			htmlFile << "						</ul>" << endl;
			htmlFile << "					</div>" << endl;
			htmlFile << "				</div>" << endl;
			htmlFile << "				<!-- Side Nav END -->" << endl;
			htmlFile << "" << endl;
			htmlFile << "				<!-- Page Container START -->" << endl;
			htmlFile << "				<div class='page-container'>" << endl;
			htmlFile << "					" << endl;
			htmlFile << "					<!-- Header START -->" << endl;
			htmlFile << "					<div class='header navbar'></div>" << endl;
			htmlFile << "					<!-- Header END -->" << endl;
			htmlFile << "" << endl;
			htmlFile << "					  <!-- Content Wrapper START -->" << endl;
			htmlFile << "					  <div class='main-content'>" << endl;
			htmlFile << "							<div class='container-fluid'>" << endl;
			htmlFile << "" << endl;
			htmlFile << "								<!-- Your content goes here -->								" << endl;
			htmlFile << "								<form class='card widget-feed col-md-8'>" << endl;
			htmlFile << "										<h1 class='feed-title card-title'>Quiz 1</h1>" << endl;
			htmlFile << "" << endl;
		}

		// The first question
		else if (questions && line != "" && question.text == "") {
			question.text = line;
		}

		// A possible response
		else if (questions && line != "" && question.text != "") {
			question.phrases.push_back(line);
		}

		// End of question
		else if (questions && line == "") {
			
			htmlFile << "										<h3 class='feed-subtitle'>" << question.text << "</h3>" << endl;
			htmlFile << "										<div class='feed-body form-group pregunta_1'>" << endl;
			htmlFile << "											<div class='row'>" << endl;
			htmlFile << "												<div class='col-sm-12'>" << endl;

			for (int i=0; i<question.phrases.size(); i++) {
				htmlFile << "													<div class='form-check'>" << endl;
				htmlFile << "														<div class='row mrg-top-30'>" << endl;
				htmlFile << "															<div class='col-1 align-self-center'>" << endl;
				htmlFile << "																<input class='quest" << numQuestion << "' type='radio' name='respuesta' id='p1_1' value='" << question.phrases[i][0] << "'>" << endl;	
				htmlFile << "															</div>" << endl;
				htmlFile << "															<div class='col-11'>" << endl;
				htmlFile << "																<label class='form-check-label' for='p1_1'>" << question.phrases[i].substr(1,question.phrases[i].size()-1) << "</label>" << endl;
				htmlFile << "															</div>" << endl;
				htmlFile << "														</div>" << endl;
				htmlFile << "													</div>" << endl;
			}

			// Not sure
			htmlFile << "												</div>" << endl;
			htmlFile << "											</div>" << endl;
			// Not sure
			htmlFile << "											<div class='row mrg-top-30'>" << endl;
			htmlFile << "												<div class='col-sm-12'>" << endl;
			htmlFile << "													<input id='check" << numQuestion << "' type='button' class='btn btn-primary btn-rounded pull-right' name='pregunta_" << numQuestion << "' value='Verificar'>" << endl;
			htmlFile << "												</div>" << endl;
			htmlFile << "											</div>" << endl;
			htmlFile << "										</div>" << endl;
			htmlFile << "" << endl;

			jsFile << "$('#check" << numQuestion << "').on('click', function() {" << endl;
			jsFile << "" << endl;
			jsFile << "	let responses = $('.quest" << numQuestion << "');" << endl;
			jsFile << "" << endl;
			jsFile << "	for (let i=0; i<responses.length; i++) {" << endl;
			jsFile << "" << endl;
			jsFile << "		if (responses[i].checked && responses[i].value == '1') {" << endl;
			jsFile << "			alert('¡Correcto!');" << endl;
			jsFile << "		}" << endl;
			jsFile << "" << endl;
			jsFile << "		else if (responses[i].checked) {" << endl;
			jsFile << "			alert('Incorrecto');" << endl;
			jsFile << "		}" << endl;
			jsFile << "	}" << endl;
			jsFile << "});" << endl;
			jsFile << "" << endl;


			numQuestion++;
			itteration++;
			question.text = "";
			question.phrases.clear();
		}
	}

	inputFile.close();
	htmlFile.close();
	jsFile.close();

	return 0;
}