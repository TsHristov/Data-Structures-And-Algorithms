;; filter: Filter a list according to a predicate:
(define (filter l p?)
  (cond
   ((null? l) l)
   ((p? (car l)) (cons (car l) (filter (cdr l) p?)))
   (else (filter (cdr l) p?))))

;; quick-sort: Quick sort implementation:
(define (quick-sort l)
  (if (null? l) l
      (append (quick-sort (filter l (lambda (x) (< x (car l)))))
	      (list (car l))
	      (quick-sort (filter (cdr l) (lambda (x) (not (< x (car l)))))))))
