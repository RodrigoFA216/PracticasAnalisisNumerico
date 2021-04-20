/*
*   Programa: Método de la secante
*
*   Autor: José Emilio Vera Cordero
*/

use std::{io::{stdin, stdout,
    Write, Read}, vec::Vec};

extern crate symbolic_polinomials;
use symbolic_polinomials::*;

type SymInt = Polynomial<String, f64, u8>;

/* Función para detener el programa hasta que se presione "Enter" */
fn pause() {
    let mut stdout = stdout();
    stdout.write(b"\nPresione ENTER para continuar...").unwrap();
    stdout.flush().unwrap();
    stdin().read(&mut [0]).unwrap();
    println!("");
}

fn main() {
    let mut solve: String = String::new();
    print!("Dé f(x): ");
    Write::flush(&mut stdout())
        .expect("No fue posible imprimir");
    stdin()
        .read_line(&mut solve)
        .expect("No fue posible leer la entrada");

    let ec: SymInt = variable(solve.into());

    let mut error: String = String::new();

    print!("Dé el error: ");
    Write::flush(&mut stdout())
        .expect("No fue posible imprimir");
    stdin()
        .read_line(&mut error)
        .expect("No fue posible leer la entrada");

    let error: f64 = match xz.trim().parse() {
        Ok(value) => value,
        Err(_) => panic!("Entrada no válida."),
    }

    let mut xz: String = String::new();

    print!("Dé x₀: ");
    Write::flush(&mut stdout())
        .expect("No fue posible imprimir");
    stdin()
        .read_line(&mut xz)
        .expect("No fue posible leer la entrada");

    let mut xz: f64 = match xz.trim().parse() {
        Ok(value) => value,
        Err(_) => panic!("Entrada no válida."),
    }

    let mut xo: String = String::new();

    print!("Dé x₁: ");
    Write::flush(&mut stdout())
        .expect("No fue posible imprimir");
    stdin()
        .read_line(&mut xo)
        .expect("No fue posible leer la entrada");

    let mut xo: f64 = match xo.trim().parse() {
        Ok(value) => value,
        Err(_) => panic!("Entrada no válida."),
    }

    let mut errc: f64 = 0f64;

    // Algoritmo
    let mut i = 2;
    while error < errc {
        errc = (xo - xz).abs();
        xz = xo;

        xo = xo - (((xo - xz)*(ec.eval(xo))) / (ec.eval(xo) - ec.eval(xz)));

        println!("It {:1}: X{} = {}; E = {}", i, xo, errc);

        ++i;
    }
}
