MODULE UFM
  IMPLICIT NONE
  PRIVATE
  
  PUBLIC :: Union_Find

  TYPE Union_Find
    INTEGER                            :: n_elements
    INTEGER                            :: n_groups
    INTEGER, DIMENSION(:), ALLOCATABLE :: id, sz
  CONTAINS
    PROCEDURE, PUBLIC, PASS(this) :: insert
    PROCEDURE, PUBLIC             :: find
    PROCEDURE, PUBLIC             :: connected
    PROCEDURE, PUBLIC             :: groups_cnt
    PROCEDURE, PUBLIC, PASS(this) :: info
  END TYPE Union_Find

CONTAINS

  SUBROUTINE insert(this, p, q)
    CLASS(Union_Find), INTENT(INOUT) :: this
    INTEGER,   INTENT(IN)            :: p, q
    
    ! LOCAL VARIABLES
    INTEGER                          :: pRoot, qRoot

    pRoot = this%find(p)
    qRoot = this%find(q)
    IF (pRoot .EQ. qRoot) THEN
      RETURN
    END IF

    IF (this%sz(pRoot) < this%sz(qRoot)) THEN
      this%id(pRoot) = qRoot
      this%sz(qRoot) = this%sz(qRoot) + this%sz(pRoot)
    ELSE
      this%id(qRoot) = pRoot
      this%sz(pRoot) = this%sz(pRoot) + this%sz(qRoot)
    END IF

    this%n_groups = this%n_groups - 1
  END SUBROUTINE insert

  FUNCTION find(this, p) RESULT(pRoot)
    CLASS(Union_Find), INTENT(IN)    :: this
    INTEGER,   INTENT(IN)            :: p

    INTEGER                          :: pRoot
    
    pRoot = p
    DO WHILE (pRoot .NE. this%id(pRoot))
      pRoot = this%id(pRoot) 
    END DO
  END FUNCTION find

  LOGICAL FUNCTION connected(this, p, q)
    CLASS(Union_Find), INTENT(IN)    :: this
    INTEGER,   INTENT(IN)            :: p, q

    connected = this%find(p) .EQ. this%find(q)
  END FUNCTION connected

  INTEGER FUNCTION groups_cnt(this)
    CLASS(Union_Find), INTENT(IN)    :: this

    groups_cnt = this%n_groups
  END FUNCTION groups_cnt

  SUBROUTINE info(this)
    CLASS(Union_Find), INTENT(IN)    :: this
    
    ! LOCAL VARIABLES
    INTEGER :: idx
    WRITE(*,*) "Total Groups:", this%groups_cnt()
    DO idx = 1, this%n_elements
      WRITE(*,*) idx, "->", this%id(idx)
    END DO
  END SUBROUTINE info
END MODULE UFM

PROGRAM UF_DEMO
  USE UFM
  IMPLICIT NONE

  ! Program Variables
  INTEGER, PARAMETER :: N = 10
  TYPE(Union_Find) :: uf
  INTEGER :: i

  ! Initialize Union_Find
  uf%n_elements = N
  uf%n_groups = N

  ALLOCATE(uf%id(N))
  ALLOCATE(uf%sz(N))


  uf%sz(:) = 1
  DO i = 1, N
    uf%id(i) = i
  END DO
  
  CALL uf%insert(4,3)
  CALL uf%insert(2,1)
  
  CALL uf%info()
  
  DEALLOCATE(uf%id)
  DEALLOCATE(uf%sz)

END PROGRAM UF_DEMO
