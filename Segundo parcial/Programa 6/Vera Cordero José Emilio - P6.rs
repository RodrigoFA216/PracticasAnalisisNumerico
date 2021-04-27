/*
 * Programa: Método de posición falsa
 *
 * Autor: José Emilio Vera Cordero
 *
 * Formulas:
 * xₘ = xf - (xf - xᵢ) * F(xf) / F(xf) - F(xᵢ)
 *
 * E = 0.001
 */

use std::{io::{stdin, stdout,
    Write, Read}, vec::Vec};

extern crate symbolic_polinomials;
use symbolic_polinomials::*;

type SymInt = Polynomial<String, f64, u8>;

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

    let mut xi: String = String::new();

    print!("Dé el punto inicial xᵢ =  ");
    Write::flush(&mut stdout())
        .expect("No fue posible imprimir");
    stdin()
        .read_line(&mut xi)
        .expect("No fue posible leer la entrada");

    let mut xi: f64 = xi
        .trim().parse()
        .expect("Entrada no válida.");

    let mut xf: String = String::new();

    print!("Dé el punto final xf = ");
    Write::flush(&mut stdout())
        .expect("No fue posible imprimir");
    stdin()
        .read_line(&mut xf)
        .expect("No fue posible leer la entrada");

    let xf: f64 = xf
        .trim().parse()
        .expect("Entrada no válida.");

    let mut auxx: f64 = 0f64;

    /* Algoritmo */
    let mut i = 1;
    while xi < xf || error > 0.001 {
        xi = xf - (((xf - xi)*ec.eval(xf)) / (ec.eval(xf) - ec.eval(xi)));

        if i <= 1 {
            println!("It {}: xₘ{} = {}; f(xₘ) = {}", i, xi, ec.eval(xi));
        } else {
            let error = (xi - auxx).abs();
            println!("It {}: xₘ{} = {}; f(xₘ) = {}; E = {}",
                i, xi, ec.eval(xi), error);
        }

        auxx = xi;
        ++i;
    }

    pause();
}
