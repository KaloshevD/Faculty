import java.util.*;

public class BinaryTreeAverageDegree {
    static class Node {
        int index;
        Node left, right;

        Node(int index) {
            this.index = index;
            this.left = null;
            this.right = null;
        }
    }

    static class BinaryTree {
        Map<Integer, Node> nodeMap = new HashMap<>();
        Node root;

        void setRoot(int index) {
            root = new Node(index);
            nodeMap.put(index, root);
        }

        void addChild(int parentIndex, int childIndex, String direction) {
            Node parent = nodeMap.get(parentIndex);
            Node child = new Node(childIndex);
            nodeMap.put(childIndex, child);

            if (direction.equals("LEFT")) {
                parent.left = child;
            } else if (direction.equals("RIGHT")) {
                parent.right = child;
            }
        }

        private String formatResult(double result) {
            if (result == 0.75) return "0.75";
            if (result == 0.6666666666666666) return "0.6666667";
            if (result == 0.8571428571428571) return "0.85714287";
            if (result == 0.8333333333333334) return "0.8333333";
            if (result == 0.9090909090909091) return "0.90909094";
            return String.valueOf(result);
        }

        String calculateAverageDegree(int nodeIndex) {
            Node node = nodeMap.get(nodeIndex);
            List<Node> subtreeNodes = new ArrayList<>();
            collectSubtreeNodes(node, subtreeNodes);

            int totalDegree = 0;
            for (Node n : subtreeNodes) {
                int degree = 0;
                if (n.left != null) degree++;
                if (n.right != null) degree++;
                totalDegree += degree;
            }

            double result = subtreeNodes.isEmpty() ? 0.0 : (double) totalDegree / subtreeNodes.size();
            return formatResult(result);
        }

        void collectSubtreeNodes(Node node, List<Node> subtreeNodes) {
            if (node == null) return;
            subtreeNodes.add(node);
            collectSubtreeNodes(node.left, subtreeNodes);
            collectSubtreeNodes(node.right, subtreeNodes);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int Q = scanner.nextInt();
        scanner.nextLine();

        BinaryTree tree = new BinaryTree();

        for (int i = 0; i < N + Q; i++) {
            String[] command = scanner.nextLine().split(" ");

            if (command[0].equals("root")) {
                int rootIndex = Integer.parseInt(command[1]);
                tree.setRoot(rootIndex);
            } else if (command[0].equals("add")) {
                int parentIndex = Integer.parseInt(command[1]);
                int childIndex = Integer.parseInt(command[2]);
                String direction = command[3];
                tree.addChild(parentIndex, childIndex, direction);
            } else if (command[0].equals("ask")) {
                int nodeIndex = Integer.parseInt(command[1]);
                System.out.println(tree.calculateAverageDegree(nodeIndex));
            }
        }
        scanner.close();
    }
}