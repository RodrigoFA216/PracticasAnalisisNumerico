/*
 * Autor: Vera Cordero José Emilio
 *
 * Programa: Método de Gauss para
 * sistemas de ecuaciones 3x3
 */

use std::{io::{stdin, stdout,
    Write, Read}};

fn pause() {
    let mut stdout = stdout();
    stdout.write(b"\nPresione ENTER para continuar...").unwrap();
    stdout.flush().unwrap();
    stdin().read(&mut [0]).unwrap();
    println!("");
}

/* Resuelve el sistemas de ecuaciones por el método de Gauss */ 
fn solve_gauss(mut matrix: [[f64; 4]; 3]) {
    let mul1 = (matrix[1][0] / matrix[0][0]) * -1.0;
    let mul2 = (matrix[2][0] / matrix[0][0]) * -1.0;

    for i in 0..=3 {
        matrix[1][i] += mul1*matrix[0][i];
        matrix[2][i] += mul2*matrix[0][i];
    }

    let mul3 = (matrix[2][1] / matrix[1][1]) * -1.0;

    for i in 0..=3 {
        matrix[2][i] += mul3*matrix[1][i];
    }

    println!("\nLa matriz resuelta es:");
    for i in 0..=2 {
        println!("{:.2}x₁+({:.2}x₂)+({:.2}x₃) = {:.2}", matrix[i][0],
            matrix[i][1], matrix[i][2], matrix[i][3]);
    }

    let x3 = matrix[2][3] / matrix[2][2];
    
    let x2 = ((-1.0*matrix[1][2]*x3) +
        (matrix[1][3])) / matrix[1][1];

    let x1 = (-1.0*((matrix[0][1]*x2) + (matrix[0][2]*x3)) +
        matrix[0][3]) / matrix[0][0];

    println!("\nLos resultados son: ");
    println!("x₁ = {:.2}\nx₂ = {:.2}\nx₃ = {:.2}", x1, x2, x3);

}

fn main() {
    let mut matrix: [[f64; 4]; 3] = [[0f64; 4]; 3];
    
    /* Lectura de la matriz */
    for i in 0..=2 {
        for j in 0..=3 {
            let mut x: String = String::new();
            let mut var: String = String::from("x");

            match j {
                3 => {
                    print!("Dé el resultado de la ecuación {}: ", i+1);
                    Write::flush(&mut stdout())
                        .expect("No fue posible imprimir");

                    stdin()
                        .read_line(&mut x)
                        .expect("No fue posible leer la entrada");

                    matrix[i][j] = x
                        .trim().parse()
                        .expect("Número no válido o entrada erronea");
                },
                _ => {
                    match j {
                        0 => var = "x₁".to_string(),
                        1 => var = "x₂".to_string(),
                        2 => var = "x₃".to_string(),
                        _ => (),
                    }
                    print!("Dé el coeficiente de {} de la ecuación {}: ", var, i+1);
                    Write::flush(&mut stdout())
                        .expect("No fue posible imprimir");

                    stdin()
                        .read_line(&mut x)
                        .expect("No fue posible leer la entrada");

                    matrix[i][j] = x
                        .trim().parse()
                        .expect("Número no válido o entrada erronea");
                },
            }
        }
        println!();
    }

    print!("\x1B[2J\x1B[1;1H");

    println!("El sistema de ecuaciones es:");
    for i in 0..=2 {
        println!("{}x₁+({}x₂)+({}x₃) = {}", matrix[i][0],
            matrix[i][1], matrix[i][2], matrix[i][3]);
    }

    solve_gauss(matrix);
    pause();
}
