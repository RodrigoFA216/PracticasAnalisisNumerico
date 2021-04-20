/*
*   Programa: Punto fijo
*
*   Autor: José Emilio Vera Cordero
*   Fecha: 28/03/2021
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
    print!("Dé g(x): ");
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

    let num_iter: String = String::new();
    print!("Ingrese la cantidad de ciclos a realizar: ");
    Write::flush(&mut stdout())
        .expect("No fue posible imprimir");
    stdin()
        .read_line(&mut num_iter)
        .expect("No fue posible leer la entrada");

    let num_iter: i32 = match num_iter.trim().parse() {
        Ok(value) => value,
        Err(_) => panic!("Entrada no válida"),
    };

    println!("\n# Iteración {0:>8} {1:>8}",
        xi="X₀", E="E");

    let mut err_inter: f64 = 0f64;

    // Algoritmo
    for i in 1..=num_iter {
        let err = (xz - ).abs();

        xz = ec.eval(xz);

        if xz < error {
            println!("Se alcanzó el error máximo.");
            break
        }
        if xz < 0 {
            println!("El punto no converge.");
            break
        }

        if i > 1 {
            let err: f64 = (err_inter - xz).abs();
            println!("{0:>8} {1:>14.2} {2:>8.2}",
                    i, xz, err);
            err_inter = xz;
        } else {
            println!("{0:>8} {1:>14.2}", i, xz);
            err_inter = xz;
        }
    }
}
