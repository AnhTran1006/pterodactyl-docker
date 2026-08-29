# 🐉 Pterodactyl Docker

Docker images dành cho **Pelican / Pterodactyl**, tập trung vào **Oracle GraalVM** cho Java server.

## Java Oracle GraalVM

| Java        | Image                                            |
| ----------- | ------------------------------------------------ |
| Java 17 | `ghcr.io/anhtran1006/pterodactyl-docker:graalvm_17` |
| Java 21 | `ghcr.io/anhtran1006/pterodactyl-docker:graalvm_21` |
| Java 22     | `ghcr.io/anhtran1006/pterodactyl-docker:graalvm_22` |
| Java 23     | `ghcr.io/anhtran1006/pterodactyl-docker:graalvm_23` |
| Java 24     | `ghcr.io/anhtran1006/pterodactyl-docker:graalvm_24` |
| Java 25 | `ghcr.io/anhtran1006/pterodactyl-docker:graalvm_25` |

## Thêm Docker Image vào Pterodactyl

Đăng nhập **Pterodactyl Panel** bằng tài khoản Administrator.

Đi tới:

**Admin Panel → Nests → Chọn Nest → Chọn Egg → Docker Images**

Thêm image cần sử dụng vào danh sách **Docker Images**.

Ví dụ:

```text
Java 21|ghcr.io/anhtran1006/pterodactyl-docker:graalvm_21
```

## Environment Variables

### CPU Spoof

`CPU_SPOOF` là Environment Variable dành cho các image **Oracle GraalVM**, cho phép thay đổi tên CPU trong container.

Để cấu hình `CPU_SPOOF` trong Pterodactyl Panel:

**Admin Panel → Nests → Chọn Nest → Chọn Egg → Variables → Create New Variable**

Cấu hình như sau:

| Field                | Giá trị                            |
| -------------------- | ---------------------------------- |
| Name                 | `CPU Spoof`                        |
| Environment Variable | `CPU_SPOOF`                        |
| Default Value        | Tên CPU muốn giả mạo hoặc để trống |
| User Viewable        | Tùy chọn                           |
| User Editable        | Tùy chọn                           |
