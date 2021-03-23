/*
*	Programa: Cálculo de errores con serie de Maclaurin
*
*	Autor: José Emilio Vera Cordero
*	Fecha: 21/08/2021
*
*
*	Serie de Maclaurin:
*	eˣ = 1 + x + x²/2! + x³/3! + … + xⁿ/n!
*
* 	Formulazo:
*	Error (E) = p* - p
*	Error absoluto (EA) = |p* - p|
*	Error relativo (ER) = EA/p
*	Error relativo porcentual (ERP) = ERx100
*/

/* cargo versión 1.50, rustc versión 1.50*/

/* Argumentos para compilar: cargo build */

use std::{io::{stdin, stdout,
	Write, Read}, convert::TryInto,
	f64::consts};
use factorial::Factorial;

/* Función para detener el programa hasta que se presione "Enter" */
fn pause() {
	let mut stdout = stdout();
	stdout.write(b"\nPresione ENTER para continuar...").unwrap();
	stdout.flush().unwrap();
	stdin().read(&mut [0]).unwrap();
	println!("");
}

fn main() {
	/* Declaración de las variables 'x' y 'n_elemenst' (número de elementos) */
	let mut x: String = String::new();
	let mut n_elements: String = String::new();

	println!("¿Cuál es es valor de x?:");
	print!("x = ");
	Write::flush(&mut stdout())
		.expect("No fue posible imprimir");
	stdin()
		.read_line(&mut x)
		.expect("No fue posible leer la entrada");

	let x: f32 = match x.trim().parse() {
		Ok(x) => x,
		Err(_) =>
			panic!("Número no válido o entrada
				erronea"),
	};

	println!("\n¿Cuántas iteraciones quiere realizar?:");
	print!("# Elementos = ");
	Write::flush(&mut stdout())
		.expect("No fue posible imprimir");
	stdin()
		.read_line(&mut n_elements)
		.expect("No fue posible leer la entrada");

	let n_elements: u32 = match n_elements.trim().parse() {
		Ok(n_elements) => n_elements,
		Err(_) =>
			panic!("Número no válido o entrada
				erronea"),
	};

	/* Declaración y evaluación de 'e' (eˣ) */
	let e: f64 = consts::E.powf(x as f64);
	/* Declaración de 'p_aprox' (valor aproximado = p*) */
	let mut p_aprox: f64 = 1f64;

	println!("\n  x = {}\n  eˣ = {}...", x, e);

	/* Imprime la tabla con formato */
	println!("\n# Elemento{p:>9}{erp:>19}", p = "p*", erp = "Error ERP");

	/*
	* Ciclo en el que cada iteración se calcula un nuevo
	* valor de la serie de Maclaurin hasta que se completen
	* el número de Elementos dados por el usuario o 'p_aprox'
	* sea mayor a 'e'
	*/
	for i in 0..=n_elements {
		let erp: f64;

		if i > 0 {
			p_aprox += (x.powi((i).try_into().unwrap())
				/ (i).factorial() as f32) as f64;
			erp = (p_aprox - e).abs() / e * 100f64;
		} else {
			erp = (p_aprox - e).abs() / e * 100f64;
		}

		if p_aprox > e {
			println!("Se alcanzó el error porcentual máximo.");
			break
		}

		println!("{0:>6}{1:>16.7}{2:>15.7}%", i+1, p_aprox, erp);
	}

	pause();
}