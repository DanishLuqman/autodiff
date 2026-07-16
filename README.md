## Autodiff in C

### Planned folder structure

```text
autodiff/
├── Makefile
├── README.md
├── include/ad/          # Public API — one header per module
│   ├── ad.h             # Umbrella header, includes the rest
│   ├── arena.h
│   ├── vec.h
│   ├── tensor.h         # struct Tensor, views, elementwise, reduce
│   ├── matmul.h
│   ├── node.h           # struct Node, tape, backward()
│   ├── ops.h            # Differentiable ops
│   ├── nn.h             # Linear, activations, losses
│   └── optim.h
├── src/
│   ├── core/
│   │   ├── arena.c
│   │   └── vec.c
│   ├── tensor/
│   │   ├── tensor.c        # Alloc, strides, contiguous
│   │   ├── view.c          # Reshape, transpose, slice
│   │   ├── elementwise.c
│   │   ├── broadcast.c     # unbroadcast() lives here
│   │   ├── reduce.c
│   │   └── matmul.c
│   ├── autograd/
│   │   ├── tape.c
│   │   ├── ops.c           # Forward + backward pairs
│   │   └── engine.c        # Topo sort, backward walk
│   └── nn/
│       ├── linear.c
│       ├── activation.c
│       ├── loss.c
│       └── optim.c
├── tests/
│   ├── test_main.c         # Runner
│   ├── gradcheck.c         # + gradcheck.h
│   ├── test_tensor.c
│   ├── test_matmul.c
│   └── test_ops.c
├── bench/
│   └── bench_matmul.c
├── examples/
│   ├── xor.c
│   └── mnist.c
└── data/                   # Gitignored