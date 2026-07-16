## Autodiff in C

### Planned folder structure

autodiff/
├── Makefile
├── README.md
├── include/ad/          # public API — one header per module
│   ├── ad.h             # umbrella header, includes the rest
│   ├── arena.h
│   ├── vec.h
│   ├── tensor.h         # struct Tensor, views, elementwise, reduce
│   ├── matmul.h
│   ├── node.h           # struct Node, tape, backward()
│   ├── ops.h            # differentiable ops
│   ├── nn.h             # linear, activations, losses
│   └── optim.h
├── src/
│   ├── core/
│   │   ├── arena.c
│   │   └── vec.c
│   ├── tensor/
│   │   ├── tensor.c        # alloc, strides, contiguous
│   │   ├── view.c          # reshape, transpose, slice
│   │   ├── elementwise.c
│   │   ├── broadcast.c     # unbroadcast() lives here
│   │   ├── reduce.c
│   │   └── matmul.c
│   ├── autograd/
│   │   ├── tape.c
│   │   ├── ops.c           # forward + backward pairs
│   │   └── engine.c        # topo sort, backward walk
│   └── nn/
│       ├── linear.c
│       ├── activation.c
│       ├── loss.c
│       └── optim.c
├── tests/
│   ├── test_main.c         # runner
│   ├── gradcheck.c         # + gradcheck.h
│   ├── test_tensor.c
│   ├── test_matmul.c
│   └── test_ops.c
├── bench/
│   └── bench_matmul.c
├── examples/
│   ├── xor.c
│   └── mnist.c
└── data/                   # gitignored