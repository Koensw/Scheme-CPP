#lang racket

(define (even? n)
  (= (remainder n 2) 0))

(define (fast-expt b n)
  (fast-iter 1 b n))

(define (fast-iter a b n)
  (cond ((= n 1) a)
        ((even? n) (fast-iter (* a b b) b (/ n 2)))
        (else (fast-iter (* a b) b (- n 1)))
        ))
     
(define (double a)
  (+ a a))

(define (* a b)
  (cond ((= b 1) a)
        ((even? b) (double (* a (/ b 2))))
        (else (+ a (* a (- b 1))))
        ))


 ;; ex 1.19 
  
 (define (fib n) 
   (fib-iter 1 0 0 1 n)) 
 (define (fib-iter a b p q count) 
   (cond ((= count 0) b) 
         ((even? count) 
          (fib-iter a 
                    b 
                    (+ (square p) (square q)) 
                    (+ (* 2 p q) (square q)) 
                    (/ count 2))) 
         (else (fib-iter (+ (* b q) (* a q) (* a p)) 
                         (+ (* b p) (* a q)) 
                         p 
                         q 
                         (- count 1))))) 
  
 (define (square x) (* x x)) 