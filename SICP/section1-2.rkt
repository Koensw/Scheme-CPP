#lang racket

(define (square a)
  (* a a))

(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp)
         (remainder (square (expmod base (/ exp 2) m))
                    m))
        (else
         (remainder (* base (expmod base (- exp 1) m))
                    m))))        

(define (smallest-divisor n)
  (find-divisor n 2))
(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (+ test-divisor 1)))))
(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (cond ((= (smallest-divisor n) n) true)
        (else false)))

(define (find-primes s times)
  (define (iter s times)
    (cond ((= times 0) 0)
          ((prime? s) 
           (display s)
           (newline)
           (iter (+ s 1) (- times 1)))
          (else
           (iter (+ s 1) times))))
  (define (test s times time)
    (iter s times)
    (display " *** ")
    (display (- (current-inexact-milliseconds) time)))
  (test s times (current-inexact-milliseconds)))
  