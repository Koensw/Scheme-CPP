#lang racket

(define (simpson f a b n)
  (define h (/ (- b a) n))
  (define (iter k)
    (cond ((>= (+ a (* k h)) b) 0)
    (else (+ (* (f (+ a (* k h))) 2) (* (f (+ a (* (+ k 1) h))) 4) (iter (+ k 2))))))
   
  (* (/ h 3) (+ (* 2 (f a)) (iter 1) (* 2 (f b)))))

(define (cube x)
  (* x x x))

(simpson cube 0 1 2000)