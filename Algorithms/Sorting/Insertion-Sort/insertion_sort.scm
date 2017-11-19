;; filter*: Filter a list according to a predicate:
(define (filter* l p?)
  (cond
   ((null? l) l)
   ((p? (car l)) (cons (car l) (filter* (cdr l) p?)))
   (else (filter* (cdr l) p?))))
    
;; insert-in-sorted: Inserts a value in it`s proper position in a sorted array.
(define (insert-in-sorted val l)
  (append (filter* l (lambda (x) (< x val)))
	  (list val)
	  (filter* l (lambda (x) (>= x val)))))

;; insertion-sort: Performs insertion-sort on a list and returns it`s sorted version:
(define (insertion-sort l)
  (define (helper l res)
    (if (null? l) res
	(helper (cdr l) (insert-in-sorted (car l) res))))
  (helper l '()))
