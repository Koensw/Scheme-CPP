(define (map f l)
  (if (null? l)
      nil
      (cons (f (car l)) (map f (cdr l))))

(define (unique-pairs n)
  (define (generate c l)
    
    )