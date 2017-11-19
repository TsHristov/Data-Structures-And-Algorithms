;; min: Finds the minimum of two numbers:
(define (min x y) (if (< x y) x y))

;; min-el: Finds the minimum element in a list:
(define (min-el l) (fold-right min (car l) l))

;; remove-first: Removes the first occurence of a given element in a list:
(define (remove-first x l)
  (if (null? l) l
      (if (= (car l) x) (cdr l)
	  (cons (car l) (remove-first x (cdr l))))))

;; remove-min: Removes the first occurence of the minimum element in a list:
(define (remove-min l)
  (remove-first (min-el l) l))

;; selection-sort: Sorts a given list using Selection Sort:
(define (selection-sort l)
  (if (null? l) l
      (cons (min-el l) (selection-sort (remove-min l)))))
